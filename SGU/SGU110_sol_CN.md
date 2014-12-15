# Summary

在一个三维立体空间上有N个球，从一个起点s向d方向发出一束光，问这束光在这些球之中如何反射，要求给出每次碰到的球的ID，如果反射次数大于 十，那么后面的都输出“etc.”。此外，如果光线与球面相切，那么仍认为光线与球“碰撞”了。

# Solution

题目的难点有两个：一是求直线和球的交点，二是求向量在球切面上的旋转。

（1）处理第一个问题，可以使用解析几何的思想。

直线的参数方程为：
l = p + t * v
其中，p为直线的一个点，v为直线的方向向量，t为参数。

（2）球面的参数方程为：

(u - v)<sup>2</sup> = R<sup>2</sup>
其中，u为球面上的一个点，c为球心，R为半径。

要求交点，那么连理两个方程，将l代入圆的参数方程即可。这时问题就变成解一个一元二次方程。如果方程无解，那么说明球与直线没有交点。如
果解出来的参数t&lt;0，必须忽略。对于有多个t，取t的最小值且t&gt;0。