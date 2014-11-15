//
//  catalog.cpp
//  MiniSQL
//
//  Created by 冯喆￼ on 14-10-23.
//  Copyright (c) 2014年 冯喆￼. All rights reserved.
//

#include "catalog.h"
#include "error.h"
#include "tinyxml.h"
#include <stdio.h>

void Catalog::read_file()
{
    const char * xmlFile = "catalog.xml";
    TiXmlDocument doc;
    doc.LoadFile(xmlFile);
    
    std::string value;
    Database_info database_info;
    Table_info table_info;
    Attribute attribute_info;
    
    database_list.clear();
    
    TiXmlElement* database_element = doc.RootElement();
    for (; database_element != NULL; database_element = database_element->NextSiblingElement() )
    {
        TiXmlAttribute* database_name = database_element->FirstAttribute();
        //std::cout << database_name->Name() << " : " << database_name->Value() << std::endl;
    
        TiXmlElement* table_element = database_element->FirstChildElement();
        for (; table_element != NULL; table_element = table_element->NextSiblingElement() )
        {
            TiXmlAttribute* table_name = table_element->FirstAttribute();
            //std::cout << table_name->Name() << " : " << table_name->Value() << std::endl;
    
            TiXmlElement* attribute_element = table_element->FirstChildElement();
            for (;attribute_element != NULL; attribute_element = attribute_element->NextSiblingElement() )
            {
                TiXmlAttribute* attribute_name = attribute_element->FirstAttribute();
                //std::cout << attribute_name->Name() << " : " << attribute_name->Value() << std::endl;
                
                TiXmlElement* attribute_son = attribute_element->FirstChildElement();
                value=attribute_son->GetText();
                if (value=="int")
                {
                    attribute_info.type=SQL_INT;
                }
                else if (value=="float")
                {
                    attribute_info.type=SQL_FLOAT;
                }
                else if (value=="string")
                {
                    attribute_info.type=SQL_STRING;
                }
                
                attribute_son = attribute_son->NextSiblingElement();
                value=attribute_son->GetText();
                int n = atoi(value.c_str());
                attribute_info.size=n;
                
                attribute_son = attribute_son->NextSiblingElement();
                value=attribute_son->GetText();
                if  (value=="1")
                {
                    std::cout<<"flag"<<std::endl;
                    attribute_info.is_primary=1;
                }
                else
                {
                    attribute_info.is_primary=0;
                }
                
                attribute_son = attribute_son->NextSiblingElement();
                value=attribute_son->GetText();
                if  (value=="1")
                {
                    attribute_info.is_only=1;
                }
                else
                {
                    attribute_info.is_only=0;
                }
                
                attribute_son = attribute_son->NextSiblingElement();
                value=attribute_son->GetText();
                if  (value=="1")
                {
                    attribute_info.has_index=1;
                    attribute_son = attribute_son->NextSiblingElement();
                    attribute_info.index_name=attribute_son->GetText();
                }
                else
                {
                    attribute_info.has_index=0;
                }
                
                value=attribute_name->Value();
                attribute_info.attribute_name=value;
                
                table_info.attribute_list.push_back(attribute_info);
            }
            
            value=table_name->Value();
            table_info.table_name=value;

            database_info.table_list.push_back(table_info);
            table_info.attribute_list.clear();
        }
        
        value=database_name->Value();
        database_info.database_name=value;
        
        database_list.push_back(database_info);
        database_info.table_list.clear();
    }
    
}

void Catalog::write_file()
{
    TiXmlDocument doc;
    int i,j,k;
    int flag;
    char ch[100];
    
    TiXmlElement * database_element[10];
    TiXmlElement * table_element[32];
    TiXmlElement * attribute_element[32];
    
    for (i=0; i<database_list.size(); i++)
    {
        database_element[i] = new TiXmlElement( "Databse" );
        strcpy(ch,database_list[i].database_name.c_str());
        database_element[i]->SetAttribute("name", ch);
        
        for (j=0; j<database_list[i].table_list.size(); j++)
        {
            table_element[j] = new TiXmlElement( "Table" );
            strcpy(ch,database_list[i].table_list[j].table_name.c_str());
            table_element[j]->SetAttribute("name", ch );
            
            for (k=0; k<database_list[i].table_list[j].attribute_list.size(); k++)
            {
                attribute_element[k] = new TiXmlElement( "Attribute" );
                strcpy(ch,database_list[i].table_list[j].attribute_list[k].attribute_name.c_str());
                attribute_element[k]->SetAttribute("name", ch);
                
                TiXmlElement * type_element = new TiXmlElement("type");
                
                switch (database_list[i].table_list[j].attribute_list[k].type) {
                    case SQL_INT:
                        strcpy(ch,"int");
                        break;
                        
                    case SQL_FLOAT:
                        strcpy(ch,"float");
                        break;
                        
                    case SQL_STRING:
                        strcpy(ch,"string");
                        break;
                }
                type_element->LinkEndChild(new TiXmlText(ch) );
                attribute_element[k]->LinkEndChild(type_element);
                
                TiXmlElement * size_element = new TiXmlElement("size");
                sprintf(ch, "%d", database_list[i].table_list[j].attribute_list[k].size);
                size_element->LinkEndChild(new TiXmlText(ch) );
                attribute_element[k]->LinkEndChild(size_element);
                
                TiXmlElement * primary_element = new TiXmlElement("is_primary");
                if (database_list[i].table_list[j].attribute_list[k].is_primary)
                    flag=1;
                else
                    flag=0;
                sprintf(ch, "%d", flag);
                primary_element->LinkEndChild(new TiXmlText(ch) );
                attribute_element[k]->LinkEndChild(primary_element);
                
                TiXmlElement * only_element = new TiXmlElement("is_only");
                if (database_list[i].table_list[j].attribute_list[k].is_only)
                    flag=1;
                else
                    flag=0;
                sprintf(ch, "%d", flag);
                only_element->LinkEndChild(new TiXmlText(ch) );
                attribute_element[k]->LinkEndChild(only_element);
                
                TiXmlElement * hasindex_element = new TiXmlElement("has_index");
                if (database_list[i].table_list[j].attribute_list[k].has_index)
                    flag=1;
                else
                    flag=0;
                sprintf(ch, "%d", flag);
                hasindex_element->LinkEndChild(new TiXmlText(ch) );
                attribute_element[k]->LinkEndChild(hasindex_element);
                
                if (flag)
                {
                    TiXmlElement * index_element = new TiXmlElement("index_name");
                    strcpy(ch,database_list[i].table_list[j].attribute_list[k].index_name.c_str());
                    index_element->LinkEndChild(new TiXmlText(ch) );
                    attribute_element[k]->LinkEndChild(index_element);
                }
                
                table_element[j]->LinkEndChild(attribute_element[k]);
            }
            
            database_element[i]->LinkEndChild(table_element[j]);
        }
        
        doc.LinkEndChild(database_element[i]);
    }
    
    doc.SaveFile( "catalog.xml" );
    
}

void Catalog::create_table(std::string database_name, Table_info table)
{
    int i,j;
    
    /*for (i=0; i < table.attribute_list.size(); i++)
    {
        if (table.attribute_list[j].has_index==1)
        {
            table.attribute_list[j].index_name=table.attribute_list[j].attribute_name;
        }
        j++;
    }*/
    
    for (i=0; i < database_list.size(); i++)
    {
        if (database_list[i].database_name == database_name)
        {
            break;
        }
    }
    if (i == database_list.size())
    {
        Error error(1);
        throw error;
    }
    else
    {
        for (j=0; j < database_list[i].table_list.size(); j++)
        {
            if (database_list[i].table_list[j].table_name==table.table_name)
            {
                Error error(3);
                throw error;
            }
        }
        database_list[i].table_list.push_back(table);
    }
}

void Catalog::create_index(Index_info index)
{
    int i=0,j=0,k=0;
    while (database_list[i].database_name != index.database_name)
    {
        i++;
    }
    while (database_list[i].table_list[j].table_name != index.table_name)
    {
        j++;
    }
    while (database_list[i].table_list[j].attribute_list[k].attribute_name != index.attribute_name)
    {
        k++;
    }
    // std::cout<<i<<database_list[i].database_name<<std::endl;
    // std::cout<<j<<database_list[i].table_list[j].table_name<<std::endl;
    database_list[i].table_list[j].attribute_list[k].index_name = index.index_name;
    database_list[i].table_list[j].attribute_list[k].has_index = 1;
}

bool Catalog::is_table(std::string database_name, std::string table_name)
{
    int i,j;
    
    for (i=0; i < database_list.size(); i++)
    {
        if (database_list[i].database_name == database_name)
        {
            break;
        }
    }
    if (i == database_list.size())
    {
        Error error(1);
        throw error;
    }
    else
    {
        for (j=0; j < database_list[i].table_list.size(); j++)
        {
            if (database_list[i].table_list[j].table_name == table_name)
            {
                return true;
            }
        }
        return false;
    }
}

bool Catalog::is_index(std::string index_name)
{
    int i,j,k;
    for (i=0; i < database_list.size(); i++)
    {
        for (j=0; j < database_list[i].table_list.size(); j++)
        {
            for (k=0; k < database_list[i].table_list[j].attribute_list.size(); k++)
            {
                if (database_list[i].table_list[j].attribute_list[k].index_name == index_name)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

Table_info Catalog::get_table(std::string database_name, std::string table_name)
{
    Table_info table_info;
    int i,j,k,size=0;
    
    for (i=0; i < database_list.size(); i++)
    {
        if (database_list[i].database_name == database_name)
        {
            break;
        }
    }
    if (i == database_list.size())
    {
        Error error(1);
        throw error;
    }
    else
    {
        for (j=0; j < database_list[i].table_list.size(); j++)
        {
            if (database_list[i].table_list[j].table_name == table_name)
            {
                database_list[i].table_list[j].database=database_list[i].database_name;
                for (k=0; k<database_list[i].table_list[j].attribute_list.size(); k++)
                {
                    size=size+database_list[i].table_list[j].attribute_list[k].size;
                }
                database_list[i].table_list[j].tuple_size=size;
                table_info=database_list[i].table_list[j];
                //std::cout << database_list[i].table_list.size() << std::endl;
                break;
            }
        }
    }
    if (j == database_list[i].table_list.size())
    {
        Error error(2);
        throw error;
    }
    
    return table_info;
}

void Catalog::drop_table(std::string database_name, std::string table_name)
{
    int i,j;
    
    for (i=0; i < database_list.size(); i++)
    {
        if (database_list[i].database_name == database_name)
        {
            break;
        }
    }
    if (i == database_list.size())
    {
        Error error(1);
        throw error;
    }
    else
    {
        unsigned long size=database_list[i].table_list.size();
        for (j=0; j < size; j++)
        {
            if (database_list[i].table_list[j].table_name==table_name)
            {
                database_list[i].table_list.erase(database_list[i].table_list.begin()+j);
                break;
            }
        }
        if (j == size)
        {
            Error error(2);
            throw error;
        }
    }
}

void Catalog::drop_index(std::string index_name)
{
    int i,j,k;
    for (i=0; i < database_list.size(); i++)
    {
        for (j=0; j < database_list[i].table_list.size(); j++)
        {
            for (k=0; k < database_list[i].table_list[j].attribute_list.size(); k++)
            {
                if (database_list[i].table_list[j].attribute_list[k].index_name == index_name)
                {
                    database_list[i].table_list[j].attribute_list[k].has_index=0;
                }
            }
        }
    }
}