﻿#pragma once
#include "httpheader.h"
#include "httpconfig.h"

namespace Bear {
namespace Core {
namespace Net {
namespace Http {

class HttpPostCommandHandler;

//XiongWanPing 2016.09.08
//处理client发来的http post命令
//支持渐进式处理，比如client上传超大文件
//https://tools.ietf.org/html/rfc7578
//RFC7578:Returning Values from Forms: multipart/form-data
//可上传文件的网站,可抓包分析 http://img.hoop8.com/index.php
class HTTP_EXPORT HttpPostHandler
{
public:
	HttpPostHandler();
	virtual ~HttpPostHandler();

	virtual int Input(ByteBuffer& inbox);
	virtual bool IsDone();

	virtual void SetConfig(std::shared_ptr<tagWebServerConfig> config)
	{
		mWebConfig = config;
	}
protected:

	enum eState
	{
		eState_WaitHttpHeader,
		eState_WaitFormDataHeader,
		eState_WaitFormDataBody,
		eState_Done,
	};
	void SwitchState(eState state);
	virtual std::shared_ptr<HttpPostCommandHandler> CreatePostHandler(std::shared_ptr<HttpHeader>);

	eState mState;
	std::shared_ptr<HttpHeader> mHeader;

	std::shared_ptr<HttpPostCommandHandler>	mCommandHander;
	std::shared_ptr<tagWebServerConfig>		mWebConfig;
};
}
}
}
}