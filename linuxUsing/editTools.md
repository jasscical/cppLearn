[参考链接](https://bbs.huaweicloud.com/blogs/detail/286007)

**sampler.log**

```
boot
book
booze
machine
boots
bungie
bark
aardvark
broken$tuff
robots
```

### grep

```shell
grep "boo" sampler.log
```

output

```
boot
book
booze
boots
```

加上行号-n

```
grep -n "boo" sampler.log
```

```
1:boot
2:book
3:booze
5:boots
```

-v输出不匹配的，即相反的

```
grep -vn "boo" sampler.log
```

```
4:machine
6:bungie
7:bark
8:aardvark
9:broken$tuff
10:robots
```

-c,统计行数，不打印匹配的具体字符串

```shell
grep -c "boo" sampler.log 
```

```
4
```

-l打印文件中含有目标字符串的文件名

```
grep -l "boo" *
```

```
editTools.md
sampler.log
```

-i是忽略大小写，对于非代码文件，比如处理匹配搜索字符串时，大小写相等

```
grep -i "BOO" sampler.log 
boot
book
booze
boots
```

-x表示精确完全匹配，换句话说，以下命令搜索没有结果，因为没有一行只包含"boo"，

```
grep -x "boo" sampler.log
```

但是“boot"是可以在文件中找到的

```
grep -nx "boot" sampler.log 
1:boot
```

-A可以查看目标字符串的上下文件内容

```
grep -A2 "boots" sampler.log 
boots
bungie
bark
```

#### 正则表达式

表示搜索以“e"结尾的字符串

```
grep "e$" sampler.log 
booze
machine
bungie
```

需要更广泛的正则表达式命令，使用 `grep -E`

比如，`？`表达将匹配1或0次出现

```
grep -E "boots?" sampler.log 
boot
boots
```

"|"表示或者

```
grep -E "boot|boots" sampler.log 
boot
boots
```

特殊字符处理

比如搜索：$，那么要加转义符号"\\"

```
grep '\$' sampler.log 
broken$tuff
```

### AWK

awk程序对输入文件的每一行进行操作。可以有一个可选的BEGIN{}部分。

然后主{ }部分运行在文件的每一行中，最后还有一个可选的END{ }

比如计算ls -l中第5列的和

```
ls -l
total 4
-rw-r--r-- 1 lqh lqh 1600 Sep 20 16:31 editTools.md
-rw-r--r-- 1 lqh lqh   69 Sep 20 12:30 sampler.log
```

如下

```
ls -l | awk 'BEGIN {sum=0} {sum=sum+$5} END{print sum}'
1669
```

sum初始化为0，然后取第5列的值求和：$5保存到sum，最终打印出来

#### awk命令行用法

根据需要多次使用 ’ -v ’ 标志将变量传递给 awk 程序，例如

```
awk -v skip=3 '{for (i=1;i<skip;i++) {getline}; print $0}' sampler.log 
booze
bungie
broken$tuff
```

### sed

sed 对输入流（文件或来自管道的输入）执行基本文本转换单通过流，所以效率很高。 但是， sed 能够管道过滤文本，特别区别于其他类型的编辑器。

sed 对输入流（文件或来自管道的输入）执行基本文本转换单通过流，所以效率很高。 但是， sed 能够管道过滤文本，特别区别于其他类型的编辑器。

```
sed -e 's/input/output/' sampler.log 
boot
book
booze
machine
boots
bungie
bark
aardvark
broken$tuff
```
