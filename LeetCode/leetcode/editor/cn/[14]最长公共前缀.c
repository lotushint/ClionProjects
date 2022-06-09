//编写一个函数来查找字符串数组中的最长公共前缀。 
//
// 如果不存在公共前缀，返回空字符串 ""。 
//
// 
//
// 示例 1： 
//
// 
//输入：strs = ["flower","flow","flight"]
//输出："fl"
// 
//
// 示例 2： 
//
// 
//输入：strs = ["dog","racecar","car"]
//输出：""
//解释：输入不存在公共前缀。 
//
// 
//
// 提示： 
//
// 
// 1 <= strs.length <= 200 
// 0 <= strs[i].length <= 200 
// strs[i] 仅由小写英文字母组成 
// 
// Related Topics 字符串 👍 1800 👎 0


//leetcode submit region begin(Prohibit modification and deletion)


char * longestCommonPrefix(char ** strs, int strsSize){
    char c[200];//用来保存公共前缀
    char s;//保存第一个单词的每个字母，与后续单词进行比较
    int flag = 1;//判断是否是公共前缀的标识
    int counter = -1;//保存公共前缀的索引
    int sn = 0;//第一个字符串的长度
    int k = 0;//第一个字符串的索引
    if(strsSize == 0){//字符串数组为空，返回空前缀
        return "";
    }
    while (true){
        if(strs[0][k] != '\0'){
            counter++;
        } else{
            break;
        }
        k++;
    }
    for (int i = 0; i < k; ++i) {//每次循环取第一个单词的第i个字母
        s = strs[0][i];//将第一个单词的第i个字母赋值给s
        for (int j = 1; j < strsSize; ++j) {//将s与后续单词的第i个字母比较
            if(s != strs[j][i]){
                flag = 0;
                break;
            } else{
                flag = 1;
            }
        }
        if(flag == 1){
            counter += 1;
            c[counter] = s;
        }
    }
    return c;
}
//leetcode submit region end(Prohibit modification and deletion)
