#pragma once
#include "CoreMinimal.h"

enum VerbosityLevel
{
	FATAL,
	ERROR,
	WARNING,
	DISPLAY,
	LOG
};


struct LoggerData
{
	
public:
	LoggerData(const VerbosityLevel& _verbosity, const string& _msg)
	{
		RunLogError(_verbosity, _msg);
	}
	
public:
	void RunLogError(const VerbosityLevel& _verbosity, const string& _msg)
	{
		switch (_verbosity)
		{
		case FATAL:
			FATAL(_msg);
			break;
		case ERROR:
			ERROR(_msg);
			break;
		case WARNING:
			WARNING(_msg);
			break;
		case DISPLAY:
			DISPLAY(_msg);
			break;
		case LOG:
			LOG(_msg);
			break;
		default:
			break;
		}
	}
};

