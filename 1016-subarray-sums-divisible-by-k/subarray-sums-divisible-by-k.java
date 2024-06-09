class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        mp.put(0, 1);
        int prefixSum = 0, res = 0;

        for (int num : nums) {
            prefixSum += num;
            int mod = prefixSum % k;
            mod = (mod < 0) ? mod + k : mod;
            
            if (mp.containsKey(mod)) 
                res += mp.get(mod);
            
            mp.putIfAbsent(mod, 0);
            mp.put(mod, mp.get(mod) + 1);
        }

        return res;
    }
}