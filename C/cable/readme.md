# 描述
该程序可以判断从 Franklin Pierce 往后的 31 位美国总统是民主党还是共和党。
你甚至可以用这个程序检测一些 IT 大佬的 Mac / PC 阵营：
注意总统名要小写，republican 和 democrat 顺序不能颠倒。

# 使用方法
gcc -Wall cable.c -o cable 
./cable obama republican democrat 判断总统阵营
./cable Cooper Mac PC             判断IT大佬阵营