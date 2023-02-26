#include<stdio.h>
#include<stdbool.h>

/****
概率学尝试法，不得不说很牛皮
****/

#define MAX 100000

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    int a,b;
    srand((unsigned int)time(0));//初始化种子为随机值
    for(int i=0;i<MAX;i++){
        a = rand()%(numsSize);    //随机中心点
        b = rand()%(numsSize);    

        if(abs(a-b)<= k && a != b && nums[a]==nums[b]) return true;
    }
    return false;
}

int main()
{
//	int nums[] = {1,0,1,1};
//	int k = 1;

//	int nums[] = {1,2,3,1};
//	int k = 3;

	int nums[] = {1,2,3,1,2,3};
	int k = 2;

	if(containsNearbyDuplicate(nums, sizeof(nums)/sizeof(int), k))
	{
		printf("it's true\n");
	}
	else
	{
		printf("it's false\n");
	}

	return 0;
}
