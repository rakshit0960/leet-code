import java.util.*;

class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        if (nums.length % k != 0) return false;
        Map<Integer, Integer> map = new TreeMap<>();

        for (int num : nums) {
            map.putIfAbsent(num, 0);
            map.put(num, map.get(num) + 1);
        }   

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int num = entry.getKey();
            int count = entry.getValue(); 
            if (count == 0) continue;
            
            System.out.println(num + " " + count);
            for (int i = 0; i < k; i++) {
                if (!map.containsKey(num + i) || map.get(num + i) < count) return false;
                map.put(num + i, map.get(num + i) - count);
            }
        }
        return true;
    }
}