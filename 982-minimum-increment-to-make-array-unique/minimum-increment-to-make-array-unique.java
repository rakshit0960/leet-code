import java.util.*;

class Solution {
    public int minIncrementForUnique(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();

        int maxElement = 0;
        for (int num : nums) {
            maxElement = Math.max(maxElement, num);
            map.putIfAbsent(num, 0);
            map.put(num, map.get(num) + 1);
        }

        maxElement = Math.max(maxElement, nums.length);
        int res = 0;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i <= 2 * maxElement; i++) {
            if (i > maxElement && stack.empty()) break;
            if (!map.containsKey(i)) {
                if (stack.isEmpty()) continue;
                int top = stack.peek();
                res += i - top;
                map.put(top, map.get(top) - 1);
                if (map.get(top) <= 1) stack.pop();
            }        
            else if (map.get(i) > 1) {
                stack.push(i);
            }
        }

        return res;
    }
}