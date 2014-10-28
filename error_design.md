#Error
Our Mini SQL must contribute a complete Error Processing mechanism.I have made the Error class.When writing our MiniSQL, please use the error class.
##c++ review
pleas review the syntax about exception.such as
	
	try
	{
		...
	}
	catch(..)
	{
		...
	}
##About class Error
The class name is Error.
###throw an error
if you want to throw an error, for example you think the user input a wrong table name, write code like this:
	
	Error newerror(<errornumber>,"table name error");
	throw newerror;
errornumber is the index in errorlist[], means the base type of the error, for example, table name error is a kind of "SQL syntax error".
###create a new error type
if your error type is not in the error_list in error.cpp, you must add it in the error_list in error.cpp.It's the error_list now:

	const std::string Error::error_list[]={
   		"database storage failed",	//1
  		"..."						//2
	};
if your error is  "SQL syntax error", then you can change the code to:
	
	const std::string Error::error_list[]={
   		"database storage failed",	//1
  		"SQL syntax error"			//2
  		"..."
	};
###catch an error 
you don't need to catch the error everywhere, We would catch it in main function, but if you need to catch your error, just catch it.