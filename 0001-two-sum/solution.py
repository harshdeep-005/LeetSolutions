class Solution(object):
    def twoSum(self, nums=[2,7,11,15], target=9):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # nums=
        # target=9
        y=[]
        x=0
        for i in range(len(nums)):
            for j in range(len(nums)):
                if nums[i]+nums[j]==target and i!=j:
                    x=1
                    y.append(i)
                    y.append(j)
                    return y
                    break
                else:
                    j+=1
            if x==1:
                break
            else:
                i+=1
        
