//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。 
//
// 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。 
//
// 
//
// 示例 1： 
//
// 
//输入：x = 121
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：x = -121
//输出：false
//解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
// 
//
// 示例 3： 
//
// 
//输入：x = 10
//输出：false
//解释：从右向左读, 为 01 。因此它不是一个回文数。
// 
//
// 示例 4： 
//
// 
//输入：x = -101
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// -2³¹ <= x <= 2³¹ - 1 
// 
//
// 
//
// 进阶：你能不将整数转为字符串来解决这个问题吗？ 
// Related Topics 数学 👍 1625 👎 0


//leetcode submit region begin(Prohibit modification and deletion)


bool isPalindrome(int x) {
    int result = 0;
    int remain;
    if (x == 0) {
        return true;
    } else if (x > 0) {
        int y = x;//定义一个变量保存x
        while (x != 0) {
            remain = x % 10;
            if (result > 2147483647/ 10 || result < -2147483648 /10) {//判断整数范围
                return false;
            }
            result = result * 10 + remain;
            x = x / 10;
        }
        if(result == y){
            return true;
        } else{
            return false;
        }

    } else {
        return false;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
