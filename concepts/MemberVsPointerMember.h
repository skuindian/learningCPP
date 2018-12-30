#pragma once

namespace NMemberVsPointerMember
{
	class BClass
	{
		int arr[10];
	};

	class DClass
	{
		BClass bClass;
	};

	class AClass
	{
		BClass *bClass;
	};
}