# heap sort

  堆排序

## 二叉堆

  数组的抽象，数组下标从1开始
  LEFT(i) = i * 2
  RIGHT(i) = i * 2 + 1
  PARENT(i) = i / 2
  对于每个节点一定是大于(最大堆)/小于(最小堆)它的子结点
  应该有的API:

  ```c, no_run
  void make_heap(array, len, begin)		// 将长度为len的数组,从下标为begin的指针开始保持最大/小堆
  void heap_ify(array, len)	// 维护array作为最大/小堆的性质
  ```

## 使用二叉堆排序

  ```c, no_run
  void
  heap_sort(array, len)
  {
  	while len > 1:
		heap_ify(array, len)
		swap(array[1], array[len])
		len -= 1
  }
  ```

  运行过array经过heap sort 之后为倒序的数组


