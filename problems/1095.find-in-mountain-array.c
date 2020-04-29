#define MID(a,b) (((a)+(b))/2)

/**
 * *********************************************************************
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int get(MountainArray *, int index);
 * int length(MountainArray *);
 */

int findInMountainArray(int target, MountainArray* mountainArr) {
	int len = length(mountainArr);
	int off1 = 0;
	int off2 = len - 1;
	int offm1 = MID(off1, off2);
	int offm2 = offm1 + 1;
	int valm1, valm2;
	int moff, mval;
	int offm, valm;

	if (get(mountainArr, 0) == target)
	{
		return 0;
	}

	if (len > 3)
	{
		while (off1 < off2)
		{
			offm1 = MID(off1, off2);
			offm2 = offm1 + 1;
			valm1 = get(mountainArr, offm1);
			valm2 = get(mountainArr, offm2);
			if (off1 == off2 -1)
			{
				break;
			}
			if (valm1 > valm2)
			{
				off2 = offm1;
			}
			else
			{
				off1 = offm2;
			}
		}
		if (valm1 > valm2)
		{
			moff = offm1;
			mval = valm1;
		}
		else
		{
			moff = offm2;
			mval = valm2;
		}
	}
	else
	{
		moff = 1;
		mval = get(mountainArr, 1);
	}

	if (mval == target)
	{
		return moff;
	}

	if (get(mountainArr, moff - 1) == target)
	{
		return moff - 1;
	}

	off1 = 0;
	off2 = moff - 1;
	while (off1 < off2)
	{
		offm = MID(off1, off2);
		valm = get(mountainArr, offm);
		if (valm > target)
		{
			off2 = offm - 1;
			if (get(mountainArr, offm - 1) == target)
			{
				return offm - 1;
			}
		}
		else if (valm < target)
		{
			off1 = offm + 1;
			if (get(mountainArr, offm + 1) == target)
			{
				return offm + 1;
			}
		}
		else
		{
			return offm;
		}
	}

	if (get(mountainArr, moff + 1) == target)
	{
		return moff + 1;
	}
	if (get(mountainArr, len -1) == target)
	{
		return len - 1;
	}

	off1 = moff + 1;
	off2 = len - 1;
	while (off1 < off2)
	{
		offm = MID(off1, off2);
		valm = get(mountainArr, offm);
		if (valm > target)
		{
			off1 = offm + 1;
			if (get(mountainArr, offm + 1) == target)
			{
				return offm + 1;
			}
		}
		else if (valm < target)
		{
			off2 = offm - 1;
			if (get(mountainArr, offm - 1) == target)
			{
				return offm - 1;
			}
		}
		else
		{
			return offm;
		}
	}

	return -1;
}
