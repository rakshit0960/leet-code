use std::cmp::max; 
// struct Solution;


impl Solution {
    pub fn max_satisfied(customers: Vec<i32>, grumpy: Vec<i32>, minutes: i32) -> i32 {
        let n = customers.len();        
        
        let mut current_sum = 0;
        let mut max_sum = 0;
        let min_usize = match usize::try_from(minutes) {
            Ok(u32) => u32,
            Err(e) => 0,        // default value
        };
        for (index, &is_grumpy) in (&grumpy[0..min_usize]).iter().enumerate() {
            current_sum += if is_grumpy == 1 { customers[index] } else { 0 };
            max_sum = max(current_sum, max_sum);
        }

        for (index, &is_grumpy) in (&grumpy[min_usize..]).iter().enumerate() {
            current_sum -= if grumpy[index] == 1 { customers[index] } else {0 };
            current_sum += if is_grumpy == 1 { customers[index + min_usize] } else { 0 };
            max_sum = max(current_sum, max_sum);
        }

        let mut res = 0;

        for (index, &is_grumpy) in grumpy.iter().enumerate() {
            res += if is_grumpy == 0 { customers[index] } else { 0 };
        }

        res += max_sum;

        return res;
    }
}