一个有效的url，在本程序中如下：
1.://，具有该分隔符
2.分隔符之前有一个或多个字符
3.分隔符之后有一个或多个字符

url接受的字符有三种：字母，数字，其他字符。
这三个条件缺一不可。

方法：
1.找到第一个分隔符。因为这个分割符可能不满足上面的三个条件，所以需要进一步判断。
2.有可能整个文本就一个分隔符，长度需要判断。
2.1.如果长度相等，肯定就是无效。返回e。
2.2.需要进一步判断，因为可能只有头或者只有尾巴。
2.2.1.向前走，判断是否有前置有效字符，注意，如果不是有效字符也不行。停下来之后，判断位置。
2.2.1.1.如果不是在开头，证明向前走了，开头找到了。但是开头找到，不见得，尾巴有效，所以还有继续向后走。
2.2.1.1.1.要是有效，返回beg。
2.2.1.1.2.要是无效，更新beg。在进行循环找。
2.2.1.2.如果在开头，那证明开头无效，向后迭代b，即可。所以，这个url_begin函数不能结束。因为它肯定要找到开头，要么就没有开头，返回e。外面应该要套个循环。

再次梳理以下查找sep的逻辑。
1.如果找不到，直接返回e。
2.可以找到。
2.1.如果，只有sep，直接返回e。
2.2.1.sep前顶格，后面有，不行。但是此时，不返回e，迭代b即可。
2.2.2.sep后顶格，前面有，不行。此时，直接返回e。因为后面没有字符。
2.2.3.sep前后都有，必须前后至少有一个合法的字符。否则，不返回e。迭代b就可以了。

const std::string text( "w://w<<<<<<:/<<<<<://<<<<http://www.baidu.com<<<<://weibo.com" );
