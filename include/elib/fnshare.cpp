#include "fnshare.h"





namespace elibstl
{
	static PFN_NOTIFY_SYS s_pfnNotifySys = 0;
	static PFN_NOTIFY_SYS s_pfnuserNotifySys = 0;    // �ɺ��� SetUserSysNotify() ����, 
	INT WINAPI NotifySys(INT nMsg, DWORD dwParam1, DWORD dwParam2)
	{
		INT ret = 0;
		if (s_pfnNotifySys != NULL)
			ret = s_pfnNotifySys(nMsg, dwParam1, dwParam2);
		return ret;
	}


	INT WINAPI ProcessNotifyLib(INT nMsg, DWORD dwParam1, DWORD dwParam2)
	{
		INT nRet = NR_OK;
		switch (nMsg)
		{
		case NL_SYS_NOTIFY_FUNCTION:
		{
			s_pfnNotifySys = (PFN_NOTIFY_SYS)dwParam1;
			break;
		}
		case NL_FREE_LIB_DATA:

			break;
		case NL_GET_CMD_FUNC_NAMES:
			//Ӧ������������ͷ���ʵ�ֺ����ĺ�����������, 
			//���������������ͷ�����������һһ��Ӧ, 
			//�������Ա��Ϊ��Ӧ�����ĺ��������ı�ָ��(char*)��

			break;
		case NL_GET_NOTIFY_LIB_FUNC_NAME:
			//Ӧ���ء�����ϵͳ֪ͨ�ĺ�����(����������)�ĺ�������(char*)��

			break;
		case NL_GET_DEPENDENT_LIBS:
			//Ӧ���ء������ĵ�������̬���ļ��б���, ��ʽΪ\0�ָ����ı�, ��β����\0��

			break;
		default:
			nRet = NR_ERR;
			break;
		}

		//�����û�����
		if (s_pfnuserNotifySys)
			nRet = s_pfnuserNotifySys(nMsg, dwParam1, dwParam2);

		return nRet;
	}

	PFN_NOTIFY_SYS __stdcall SetUserSysNotify(PFN_NOTIFY_SYS pfn)
	{
		s_pfnuserNotifySys = pfn;
		return ProcessNotifyLib;
	}
}