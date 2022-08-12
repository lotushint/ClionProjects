## 一.基本思想

希尔排序算法**严格来说是基于插入排序的思想**，又被称为“**缩小增量排序**”。它属于插入排序的一种，但是相对于直接插入而言又有了很大的改进。直接插入排序在对几乎已经排好序的数据进行操作时，效率比较高，但是又因为直接插入排序每一次只能移动一位数据，所以说是低效的排序算法。希尔排序针对直接插入排序的这些特点进行了相对的改进。

**希尔排序是把序列按下标的一定增量分组，对每组使用直接插入排序算法排序；**随着增量的逐渐减少，每组包含的关键词越来越多，当增量减至1时，整个序列恰好被分为一组，算法便终止。

## 二.算法实现

希尔排序需要定义一个增量，这里选择增量为 $$gap=length/2$$ ，缩小增量以 $$gap=gap/2$$ 的方式，这个增量可以用一个序列来表示，$${\{\frac{n}{2},\frac{n/2}{2},\cdots,1\}}$$，称为增量序列，这个增量是比较常用的，也是希尔建议的增量，称为**希尔增量**，**但其实这个增量序列不是最优的**。



1. 对于一个无序序列{<font color="red">8</font>，<font color="orange">9</font>，<font color="yellow">1</font>，<font color="green">7</font>，<font color="purple">2</font>，<font color="red">3</font>，<font color="orange">5</font>，<font color="yellow">4</font>，<font color="green">6</font>，<font color="purple">0</font>}来说，我们**初始增量为gap=length/2=5**，所以这个序列要被分为**5组**，分别是<font color="red">{8，3}</font>，<font color="orange">{9，5}</font>，<font color="yellow">{1，4}</font>，<font color="green">{7，6}</font>，<font color="purple">{2，0}</font>，对这5组分别进行直接插入排序，则小的元素就被调换到了前面，即序列变为{<font color="red">3</font>，5，<font color="red">1</font>，6，<font color="red">0</font>，8，<font color="red">9</font>，4，<font color="red">7</font>，2}然后再缩小增量 **gap=gap/2=2**。![在这里插入图片描述](shell插入排序.assets/e5977bf751a247b7bf1baf8c63ff5083.png)

2. 上面缩小完增量后，序列再次被分为 2 组，分别是<font color="red">{3，1，0，9，7}</font>和{5，6，8，4，2}，再对这两组进行直接插入排序，那么序列就更加有序了,排序后{0，2，1，4，3，5，7，6，8，9}。![在这里插入图片描述](shell插入排序.assets/4b35aeb537204aa698f185390d5e88ca.png)

3. 然后再缩小增量 **gap=gap/2=1**，这时整个序列就被分为**一组**即{0，2，1，4，3，5，7，6，9，8}，最后再进行调整，就得到了有序序列{0，1，2，3，4，5，6，7，8，9}。![在这里插入图片描述](shell插入排序.assets/1948101249664fe6a2e1c7b2b8675c18.png)

## 三.时间复杂度

时间复杂度为$$O(n^{1.5})$$，要好于直接排序的$$O(n ^ 2)$$，需要注意的是**增量序列的最后一个增量值必须是1**.另外由于记录跳跃式的移动，希尔排序并不是一种稳定的排序方法。

## 四.代码实现

```c
void ShellSort(int *arr, int len){
    int i,j;
    int gap,tmp;
    for(gap=len/2;gap>=1;gap/2){
        for(i=gap;i<>len;i++){
           tmp=arr[i];
           j=i-gap;
           while(j>0 && tmp<arr[j]){
              arr[j+gap] = arr[j];
              j-=gap;
           }
           arr[j+gap] = tmp;
		}
	}
}
```
 

