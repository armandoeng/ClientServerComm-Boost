#ifndef MYINPUT_H_
#define MYINPUT_H_

//---------------------------------------------------------------------------------------

class TMyInput
{
public:		
	TMyInput() = delete;
	virtual ~TMyInput() = delete;

	static int GetPort();
	static int GetFileSize();
	
private:
	static const char* fileName;
};

//---------------------------------------------------------------------------------------

#endif