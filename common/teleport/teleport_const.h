#ifndef __TELEPORT_CONST_H__
#define __TELEPORT_CONST_H__

// 注意同步更新三个不同语言的const文件

// 本文件设定teleport各个模块之间通讯时的错误值（JSON数据），包括：
//  - WEB界面与助手
//  - WEB界面与WEB后台
//  - WEB后台与CORE核心服务

//=======================================================
// 远程连接认证方式
//=======================================================
#define TP_AUTH_TYPE_NONE			0
#define TP_AUTH_TYPE_PASSWORD		1
#define TP_AUTH_TYPE_PRIVATE_KEY	2

//=======================================================
// 远程连接协议
//=======================================================
#define TP_PROTOCOL_TYPE_RDP		1
#define TP_PROTOCOL_TYPE_SSH		2
#define TP_PROTOCOL_TYPE_TELNET		3

//=======================================================
// 远程连接子协议
//=======================================================
#define TP_PROTOCOL_SUB_TYPE_RDP		100
#define TP_PROTOCOL_SUB_TYPE_SSH		200
#define TP_PROTOCOL_SUB_TYPE_SFTP		201
#define TP_PROTOCOL_SUB_TYPE_TELNET		300


//=======================================================
// 远程主机操作系统
//=======================================================
#define TP_OS_TYPE_WINDOWS	1
#define TP_OS_TYPE_LINUX	2

//=======================================================
// 远程连接会话状态
//=======================================================
#define TP_SESS_STAT_RUNNING				0		// 会话开始了，尚未结束
#define TP_SESS_STAT_END					9999	// 会话成功结束
#define TP_SESS_STAT_ERR_AUTH_DENIED		1		// 会话结束，因为认证失败
#define TP_SESS_STAT_ERR_CONNECT			2		// 会话结束，因为无法连接到远程主机
#define TP_SESS_STAT_ERR_BAD_SSH_KEY		3		// 会话结束，因为无法识别SSH私钥
#define TP_SESS_STAT_ERR_INTERNAL			4		// 会话结束，因为内部错误
#define TP_SESS_STAT_ERR_UNSUPPORT_PROTOCOL	5		// 会话结束，因为协议不支持(RDP)
#define TP_SESS_STAT_ERR_BAD_PKG			6		// 会话结束，因为收到错误的报文
#define TP_SESS_STAT_ERR_RESET				7		// 会话结束，因为teleport核心服务重置了
#define TP_SESS_STAT_ERR_IO					8		// 会话结束，因为网络中断
#define TP_SESS_STAT_ERR_SESSION			9		// 会话结束，因为无效的会话ID


//=======================================================
// 错误值
//=======================================================
#define TPE_OK						0		// 成功
//-------------------------------------------------------
// 通用错误值
//-------------------------------------------------------
#define TPE_NEED_MORE_DATA			1		// 需要更多数据（不一定是错误）
#define TPE_NEED_LOGIN				2		// 需要登录
#define TPE_PRIVILEGE				3		// 没有操作权限
#define TPE_EXISTS					8		// 目标已经存在
#define TPE_NOT_EXISTS              9		// 目标不存在

// 100~299是通用错误值

#define TPE_FAILED					100		// 内部错误
#define TPE_NETWORK					101		// 网络错误
#define TPE_DATABASE				102		// 数据库操作失败

// HTTP请求相关错误
#define TPE_HTTP_METHOD				120		// 无效的请求方法（不是GET/POST等），或者错误的请求方法（例如需要POST，却使用GET方式请求）
#define TPE_HTTP_URL_ENCODE			121		// URL编码错误（无法解码）
//#define TPE_HTTP_URI				122		// 无效的URI

#define TPE_UNKNOWN_CMD				124		// 未知的命令
#define TPE_JSON_FORMAT				125		// 错误的JSON格式（需要JSON格式数据，但是却无法按JSON格式解码）
#define TPE_PARAM					126		// 参数错误
#define TPE_DATA					127		// 数据错误

// #define TPE_OPENFILE_ERROR			0x1007	// 无法打开文件
// #define TPE_GETTEMPPATH_ERROR		0x1007
#define TPE_OPENFILE				300


//-------------------------------------------------------
// WEB服务专用错误值
//-------------------------------------------------------
#define TPE_CAPTCHA_EXPIRED			10000	// 验证码已过期
#define TPE_CAPTCHA_MISMATCH		10001	// 验证码错误
#define TPE_OATH_MISMATCH			10002	// 身份验证器动态验证码错误
#define TPE_SYS_MAINTENANCE			10003	// 系统维护中

#define TPE_USER_LOCKED				10100	// 用户已经被锁定（连续多次错误密码）
#define TPE_USER_DISABLED			10101	// 用户已经被禁用
#define TPE_USER_AUTH				10102	// 身份验证失败

//-------------------------------------------------------
// 助手程序专用错误值
//-------------------------------------------------------
#define TPE_NO_ASSIST				100000	// 未能检测到助手程序
#define TPE_OLD_ASSIST				100001	// 助手程序版本太低
#define TPE_START_CLIENT			100002	// 无法启动客户端程序（无法创建进程）



//-------------------------------------------------------
// 核心服务专用错误值
//-------------------------------------------------------
#define TPE_NO_CORE_SERVER			200000	// 未能检测到核心服务



#endif // __TELEPORT_CONST_H__
