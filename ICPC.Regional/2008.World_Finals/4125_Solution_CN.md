# 2008 World Finals: Painter
## Summary

给定平面上的N个三角形(N&lt;=100000)，判断是否有任意两个相交，如果没有，给出嵌套的最大层数。

## Solution

如果不相交，那么可以使用扫描线算法解决。

扫描线x=K从左向右扫描平面上所有的三角形，假设三角形三个点按照从左向右为p1,p2,p3，会发生如下事件点：

1. 插入事件，插入一个新的三角形的两条边(p1,p2)，(p1,p3)。
2. 变更事件，删除三角形的一条边(p1,p2)，插入(p2,p3)
3. 删除事件，退出整个三角形(p1,p3),(p2,p3)。 

![Alt text](4125_Img1.jpg "Image 1")


括号表示法：如图，用括号序列表示扫描线事件点发生后，三角形的边的在y方向的嵌套关系。图中红色表示插入事件，黄色表示变更事件，蓝色表示删除事件。
<pre>
1 ()
2 (()) 
3 (()())
4 (()())
5 ((())())
6 ((())())
7 (()())
8 (()())
9 (())
A ()
B (())
C (())
D ()
E 
</pre>
这个括号序列，也就是许多线段，可以使用平衡二叉树来维护，线段之间的大小关系就是该线段在当前扫描线时的y坐标。虽然每个括号在不同扫描线x=K的时候，y坐标都不一样，但是如果不发生线段相交的话，其位置关系是不变的。

根据扫描线算法的定义，有如下规律：

* 线段的相交只会发生在平衡树上“相邻”的两个节点中。因此只需要在插入后检查当前插入线段是否去相邻两个节点相交，删除前判断删除的线段的前后两个将要变成相邻节点的两个线段是否相交，即可判断出是否有三角形相交。
* 嵌套层数，使用depth表示，为平衡树的字段： 
<pre>
if x 为左括号 then x=pre(x).depth＋1
else if x 为右括号 then x=pre(x).depth-1
pre为前一个节点。
</pre>

实现细节

* 实现时为了不把来自同一个三角形的线段误作相交，需要在线段中记录来自哪个三角形。
* 扫描线的事件点，实际上是发生在点坐标x的偏右一点点的位置，才会产生两条线段。因此每次检查x时，先对x加上一个很小的数值eps，再计算出扫描线割该线段时对应的y坐标。
* 如果线段垂直与X轴，那么直接计算y坐标会出错。这时可以把线段中点的y坐标作为扫描线割该线段对应的y值。
* 平衡树可以使用multimap来实现，如果迭代器为it，那么it的前一个点就是it--，后一个点就是it++。 

##### Thanks
Zhang Kunwei 