#include"ElibHelp.h"


static ARG_INFO Args[] =
{
		{
			"�ӳ���ָ����ӳ����ַ",
			"��ʾ�����ӳ�������ǰ�ӡ�&�����ɵõ����ӳ���ġ��ӳ���ָ�롱���硰&�ӳ���1�����ǡ��ӳ���1�����ӳ���ָ�룻�ӳ����ַ��ͨ�������еġ�ȡ�ӳ����ַ()�������ȡ����������(&�ӳ���1)�����ص�Ҳ���ӳ���1��ִ�е�ַ��Ҳ��ͨ��WindowsϵͳAPI������GetProcAddress()����ȡ�������ⲿ�����롣",
			0,
			0,
			_SDT_ALL,
			0,
			NULL,
		},
		{
				"����ֵ",
				"���������ڽ����ӳ��򱻵��ú�ķ���ֵ��������ӳ���û�з���ֵ����Ҫ���շ���ֵ����ʡ�Ա����������ṩ������ʱ��������ṩ׼ȷ���������ͣ��������ý�����ܲ���ȷ��",
				0,
				0,
				_SDT_ALL,
				0,
				AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_VAR,
		},{
			"����",
			"������ֵ����Ϊ�������뱻�����ӳ��������Ӧ�ӳ���û�в�������ʡ�Ա������������Ӧ�ӳ����ж�����������ظ��ṩ��������������ṩ׼ȷ�Ĳ������ͺͲ�������������������Ԥ֪��",
			0,
			0,
			_SDT_ALL,
			0,
			AS_DEFAULT_VALUE_IS_EMPTY,
		}
};

#pragma region Old
//
//
//
//
//
//
//inline void CallFunction_GetValue(PMDATA_INF pMData, int& HiValue, int& LowValue, int& bytes)
//{
//	HiValue = LowValue = 0;
//	if (pMData->m_dtDataType == _SDT_NULL) return;
//	bytes = 4;
//
//	switch (pMData->m_dtDataType)
//	{
//	case SDT_INT:
//		LowValue = (int)pMData->m_int; break;
//	case SDT_SHORT:
//		LowValue = (int)pMData->m_short; bytes = 2; break;
//	case SDT_BYTE:
//		LowValue = (int)pMData->m_byte; bytes = 1; break;
//	case SDT_INT64:
//	{
//		LowValue = *(reinterpret_cast<INT*>(&pMData->m_int64));
//		HiValue = *(reinterpret_cast<INT*>(&pMData->m_int64) + 1);
//		bytes = 8;
//		break;
//	}
//	case SDT_FLOAT:
//		//LowValue = (int)pMData->m_float;  //�����϶��ǲ��е�
//	{
//		//ע��floatתint�Ĵ�����ʽ(ͨ��ST0�Ĵ�����תһ��), �ο���VC���������ɵĻ�����
//		float f = pMData->m_float;
//		int i = 0;
//		__asm fld f;
//		__asm fst i;
//		LowValue = (int)i;
//		bytes = 4;
//		break;
//	}
//	case SDT_DOUBLE:
//	case SDT_DATE_TIME:
//	{
//		LowValue = *(reinterpret_cast<INT*>(&pMData->m_double));
//		HiValue = *(reinterpret_cast<INT*>(&pMData->m_double) + 1);
//		bytes = 8;
//		break;
//	}
//	case SDT_BOOL:
//		LowValue = (int)(pMData->m_bool ? 1 : 0); bytes = 4; break;
//	case SDT_TEXT:
//		LowValue = (int)(DWORD)pMData->m_pText; break;
//	case SDT_BIN:
//	{
//		if (pMData->m_pBin == NULL) //! �ֽڼ�Ϊ�յ����!
//		{
//			LowValue = (int)0; break;
//		}
//		LowValue = reinterpret_cast<DWORD>(reinterpret_cast<LPBYTE>(pMData->m_pBin) + 2 * sizeof(INT));
//		break;
//	}
//	case SDT_SUB_PTR:
//		LowValue = (int)((DWORD)pMData->m_dwSubCodeAdr); break;
//	case _SDT_NULL:
//		LowValue = (int)0; break;
//	case SDT_STATMENT:
//		//todo: ִ������䲢ȡ��ֵ
//		LowValue = (int)0; //!!!
//		break;
//	default: LowValue = (int)pMData->m_int; break;
//	}
//}
////���Ĵ���EAX��ST0�е�ֵд��pMData
//inline void CallFunction_GetReturnedValue(PMDATA_INF pMData, int eaxValue, int edxValue, double stValue)
//{
//	if (pMData->m_dtDataType == _SDT_NULL) return;
//
//	switch (pMData->m_dtDataType)
//	{
//	case SDT_INT: case SDT_SHORT: case SDT_BYTE:
//		*(pMData->m_pInt) = eaxValue;
//		break;
//	case SDT_INT64:
//	{
//		//EAX�ڵ�λ, EDX�ڸ�λ, ���double
//		int temp[2];
//		temp[0] = eaxValue; temp[1] = edxValue;
//		*(pMData->m_pInt64) = *(INT64*)temp;
//		break;
//	}
//	case SDT_FLOAT:
//		//����VC���������ɵĴ��룬���صĸ�����(float,double)Ӧ����ST0�У������ױ��������䲻ͬ��
//		//*(pMData->m_pFloat) = (float)stValue; 
//	{
//		float f = 0;
//		__asm fld eaxValue;
//		__asm fst f;
//		*(pMData->m_pFloat) = f;
//	}
//	break;
//	case SDT_DOUBLE:
//	case SDT_DATE_TIME:
//		//����VC���������ɵĴ��룬���صĸ�����(float,double)Ӧ����ST0�У������ױ��������䲻ͬ��
//		//*(pMData->m_pDouble) = stValue;
//	{
//		//EAX�ڵ�λ, EDX�ڸ�λ, ���double
//		int temp[2];
//		temp[0] = eaxValue; temp[1] = edxValue;
//		*(pMData->m_pDouble) = *(double*)temp;
//	}
//	break;
//	case SDT_BOOL:
//		*(pMData->m_pBool) = (eaxValue != 0);
//		break;
//	case SDT_TEXT:
//		*(pMData->m_ppText) = elibstl::clone_text((char*)eaxValue);
//		break;
//	case SDT_BIN:
//		//pMData->m_pBin = CloneBinData((LPBYTE)intValue, n); //? �޷�֪���ֽڼ�����!
//		break;
//	case SDT_SUB_PTR:
//		break;
//	case _SDT_NULL:
//		break;
//	case SDT_STATMENT:
//		break;
//
//	default:
//		break;
//	}
//}
//static BOOL Global_CallFunction(PMDATA_INF pFuncMData, INT nArgCount)
//{
//
//	//ȡ�������ӳ����ִ�е�ַ(pFunc)
//	int pFunc = NULL; //pArgInf[0].m_dwSubCodeAdr;
//	int temp = 0;
//	CallFunction_GetValue(pFuncMData, temp, pFunc, temp);
//	if (pFunc == 0) return FALSE;
//
//	//����ֵ
//	PMDATA_INF pReturnMData = &pFuncMData[2];
//	//����
//	PMDATA_INF pParamsMData = &pFuncMData[3];
//
//	//�������η���ѹջ
//	int  HiValue = 0, LowValue = 0;
//	int bytes = 0;
//	int byteValue = 0;
//	int shortValue = 0;
//	if (!(pParamsMData[0].m_dtDataType == _SDT_NULL && nArgCount <= 1)) //��һ��������ʡ�Ա�ʾû�в���
//	{
//		for (int i = nArgCount - 1; i >= 0; i--) //����ѹջ
//		{
//			CallFunction_GetValue(&pParamsMData[i], HiValue, LowValue, bytes); //�������û�Ӱ�����ջ��?
//
//			//���鿴VC���������ɵĻ����룬����ѹջ������4�ֽ�Ϊ��λ
//			byteValue = (int)(byte)LowValue; shortValue = (int)(short)LowValue;
//
//			//�����8�ֽ���ֵ�Ļ�,�ȸ�λ��ջ,���λ��ջ
//			if (bytes == 8)
//			{
//				__asm PUSH HiValue;
//				__asm PUSH LowValue;
//			}
//			else if (bytes == 4)
//				__asm PUSH LowValue;
//			else if (bytes == 2)
//				__asm PUSH shortValue;
//			else if (bytes == 1)
//				__asm PUSH byteValue;
//
//		}
//	}
//
//	//�����ӳ���
//	__asm CALL pFunc;
//	int eaxValue = 0, edxValue = 0;
//	double stValue = 0.0;
//	__asm mov eaxValue, eax;
//	__asm mov edxValue, edx;
//	__asm fst stValue; //! ȡST0�Ĵ����д洢�ĸ�����ֵ(float,double)
//
//	if (pReturnMData->m_dtDataType != _SDT_NULL)
//		CallFunction_GetReturnedValue(pReturnMData, eaxValue, edxValue, stValue);
//
//	return TRUE;
//
//
//
//}
#pragma endregion



EXTERN_C void Fn_CallEfun(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf) {

	if (pArgInf->m_dtDataType != SDT_INT && pArgInf->m_dtDataType != SDT_SUB_PTR)
	{
		pRetData->m_bool = FALSE;
	}
	//4�ֽ�32λ����ѹ��
	std::uint32_t
		pEfun = pArgInf[0].m_uint;



	//�Ӻ���ǰ
	for (int i = nArgCount - 1; i > 1; i--)
	{
		std::uint32_t arg = 0;
		switch (pArgInf[i].m_dtDataType)	//	�жϲ�������
		{
			//32λ����
		case SDT_BYTE:
		case SDT_SHORT:
		case SDT_INT:
		case SDT_BOOL:
		case SDT_SUB_PTR:
		case SDT_TEXT:
			arg = pArgInf[i].m_dwSubCodeAdr;
			break;
		case SDT_FLOAT:
		{
			float f = pArgInf[i].m_float;
			int i = 0;
			__asm fld f;
			__asm fst i;
			arg = (int)i;
			break; }
		case SDT_DOUBLE:
		case SDT_DATE_TIME:
			arg = *(reinterpret_cast<std::uint32_t*>(&pArgInf[i].m_date) + 1);	//	��32λ
			_asm
			{
				push arg	//	����ѹջ
			}
			arg = *(reinterpret_cast<std::uint32_t*>(&pArgInf[i].m_date));//	��32λ
			break;
		case SDT_INT64:
			arg = *(reinterpret_cast<std::uint32_t*>(&pArgInf[i].m_int64) + 1);	//��32λ
			_asm
			{
				push arg	//	����ѹջ
			}
			arg = *(reinterpret_cast<std::uint32_t*>(&pArgInf[i].m_int64));	//	��32λ
			break;

		case SDT_BIN:
			//������IDE��ֹ��ȡ��ַ���ӳ�������ֽڼ��������ǣ���Ϊָ���ȡ��ʽ��һ��ͨ�������ԵĴ��룬���Ի��Ǽ�����
			if (pArgInf[i].m_pBin == NULL) //!��ֹΪ�շ��ʵ������ڴ�
			{
				arg = 0; break;
			}
			arg = reinterpret_cast<std::uint32_t>(pArgInf[i].m_pBin + 2 * sizeof(INT));
			break;
		}
		_asm
		{
			push arg
		}

	}
	//ִ�к���
	std::uint32_t lpart, hpart;
	_asm
	{
		call pEfun
		mov lpart, eax
		mov hpart, edx
	}

	switch (pArgInf[1].m_dtDataType)
	{

	case SDT_BYTE:
		if (pArgInf[1].m_pByte)
			*pArgInf[1].m_pByte = static_cast <std::uint8_t>(lpart);
		break;

	case SDT_SHORT:
		if (pArgInf[1].m_pShort)
			*pArgInf[1].m_pShort = static_cast <std::uint16_t>(lpart);
		break;

	case SDT_INT:
		if (pArgInf[1].m_pInt)
			*reinterpret_cast<unsigned int*>(pArgInf[1].m_pInt) = lpart;
		break;

	case SDT_INT64:
		if (pArgInf[1].m_pInt64)
		{
			LARGE_INTEGER temp;
			temp.HighPart = hpart;
			temp.LowPart = lpart;
			*pArgInf[1].m_pInt64 = *reinterpret_cast<long long*>(&temp);
		}
		break;

	case SDT_FLOAT:
		if (pArgInf[1].m_pFloat) {
			float f = 0;
			__asm fld lpart;
			__asm fst f;
			*pArgInf[1].m_pFloat = f;
		}
		break;

	case SDT_DOUBLE:
	case SDT_DATE_TIME:
		if (pArgInf[1].m_pDate)
		{
			std::uint32_t temp[2] = { lpart ,hpart };
			*(pArgInf[1].m_pDate) = *reinterpret_cast<double*>(temp);
		}
		break;
	case SDT_BOOL:
		if (pArgInf[1].m_pBool)
			*pArgInf[1].m_pBool = static_cast<int>(lpart);
		break;


	case SDT_TEXT:
		if (pArgInf[1].m_ppText)
		{
			elibstl::free(*(pArgInf[1].m_ppText));
			*(pArgInf[1].m_ppText) =
				elibstl::clone_text(reinterpret_cast<char*>(lpart));
		}
		break;


	case SDT_BIN:
		//������IDE��ֹ��ȡ��ַ���ӳ�������ֽڼ��������ǣ���Ϊָ���ȡ��ʽ��һ��ͨ�������ԵĴ��룬���Ի��Ǽ�����
		if (pArgInf[1].m_ppBin)
		{
			elibstl::free(*(pArgInf[1].m_ppBin));
			*(pArgInf[1].m_ppBin) = elibstl::clone_bin(
				reinterpret_cast<unsigned char*>(lpart), *(reinterpret_cast<std::uint32_t*>(lpart) - 1));
		}
		break;

	case SDT_SUB_PTR:
		if (pArgInf[1].m_pdwSubCodeAdr)
			*pArgInf[1].m_pdwSubCodeAdr = lpart;
		break;
	}

	pRetData->m_bool = TRUE;


}
FucInfo e_CallEfun = { {
		/*ccname*/  ("���ú���"),
		/*egname*/  ("e_call"),
		/*explain*/ ("ͬ�����Եĵ����ӳ���"),
		/*category*/12,
		/*state*/   CT_ALLOW_APPEND_NEW_ARG,
		/*ret*/     SDT_BOOL,
		/*reserved*/NULL,
		/*level*/   LVL_HIGH,
		/*bmp inx*/ 0,
		/*bmp num*/ 0,
		/*ArgCount*/3,
		/*arg lp*/  &Args[0],
	} ,Fn_CallEfun ,"Fn_CallEfun" };
