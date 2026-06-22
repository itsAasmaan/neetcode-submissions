class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums: number[], target: number): number[] {
        let lookup = new Map<number, number>();

        for (let i = 0; i < nums.length; i++) {
            let complement: number = target - nums[i];

            if (lookup.has(complement)) {
                return [lookup.get(complement)!, i];
            }

            lookup.set(nums[i], i);
        }

        return [-1, -1];
    }
}
