﻿
```http
GET / ? username = subwen % 40qq.com & phone = 1111111 & email = sub % 40qq.com & date = 2020 - 01 - 01 & sex = male & class = 3 & rule = on HTTP / 1.1
Host : 192.168.1.8 : 6789
Connection : keep - alive
Upgrade - Insecure - Requests : 1
User - Agent : Mozilla / 5.0 (Windows NT 10.0; Win64; x64) AppleWebKit / 537.36 (KHTML, like Gecko) Chrome / 80.0.3987.106 Safari / 537.36
Accept : text / html, application / xhtml + xml, application / xml; q = 0.9, image / webp, image / apng, */*;q=0.8,application/signed-exchange;v=b3;q=0.9
Accept-Encoding: gzip, deflate
Accept-Language: zh-CN,zh;q=0.9,en;q=0.8

```

```shell
第一行: 请求行
  - 第一部分: GET: 提交数据的方式
  - 第二部分: 中间橙色的字符
      - /: 访问的服务器的资源目录, / -> 代表资源根目录
      - ? 后边的内容: 客户端向服务器提交的数据
          username=subwen%40qq.com&phone=1111111&email=sub%40qq.com&date=2020-01-
          01&sex=male&class=3&rule=on
           - key=value
           - &: 间隔符, 写下前后两个键值对之间
  - 第三部分: HTTP/1.1 -> http协议的版本

第 2-8行: 请求头
  - 若干个键值对, 每个键值对占一行, 使用 \r\n 换行
  - `User-Agent: 告诉服务器当前客户端使用的浏览器的版本
第9行: 空行
```



- Post方式提交数据

  ```http
  POST / HTTP/1.1
  Host: 192.168.1.8:6789
  Connection: keep-alive
  Content-Length: 98
  Cache-Control: max-age=0
  Upgrade-Insecure-Requests: 1
  Origin: null
  Content-Type: application/x-www-form-urlencoded
  User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.106 Safari/537.36
  Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*; q = 0.8, application / signed - exchange; v = b3; q = 0.9
    Accept - Encoding: gzip, deflate
    Accept - Language : zh - CN, zh; q = 0.9, en; q = 0.8

    username = subwen % 40qq.com & phone = 1111111 & email = sub % 40qq.com & date = 2020 - 01 - 01 & sex = male & class = 1 & rule = on
    ```

    ```shell
    第1行: 请求行
    - POST : 提交数据的方式
    - / : 作为客户端访问了服务器的什么目录, / ->访问服务器提供的资源根目录
    - HTTP / 1.1 : http协议的版本号
    第 2 - 12 行 : 请求头
    - Content - Length : 客户端向服务器提交的数据块的大小 == http请求协议第四部分的数据块大小
    - Content - Type : 客户端向服务器提交的数据块的格式 == http请求协议第四部分的数据块的格式
    - 这个请求头是客户端给服务器, 服务器拿到数据之后, 就知道根据什么格式解析数据了
    第 13 行 : 空行
    第 14 行 : 客户端向服务器提交的数据
    ```



    -http中的get和post的区别
    - 功能上

    - get
    - 作为客户端向服务器申请访问以下静态资源
    - 静态资源 ?
    -网页
    - 图片
    - 文件
    - post
    - 向服务器提交动态数据
    - 用户的登录信息
    - 上传下载文件

    - 从操作的数据的量上分析

    - get:

-比较少, 使用get向服务器提交的数据在请求行的第二部分

- 在请求第二部分的数据需要显示到浏览器的地址栏中

![image - 20200328165342419](assets / image - 20200328165342419.png)

- 浏览器的地址栏存储数据需要缓存, 缓存有上限

- 如果数据量太大, 会造成数据丢失

- post:

-可以操作大数据
- 文件上传(大文件)
- post提交的数据不会显示在地址栏中, 数据在请求协议的第四部分

- 安全性:

-get :
    -提交的数据会显示到地址栏中, 容易泄露
    - post :
    -数据不会泄露, 提交的数据是看不到的

    ## 2.2 http响应

    响应消息(Response)

> -服务器给客户端回复数据使用的一种数据格式
> -http响应的组成部分 -> 4个部分
> -状态行
> -响应头(消息报头)
> -n个键值对
> -里边的信息是服务器发送给客户端
> -空行
> -响应的数据(根据客户端请求服务器给客户端回复的数据)



```http
HTTP / 1.1 200 Ok
Server : micro_httpd
Date : Fri, 18 Jul 2014 14 : 34 : 26 GMT
Content - Type : text / plain; charset = iso - 8859 - 1 (必选项)
Content - Length: 32
Location : https ://www.biadu.com
    Content - Language : zh - CN
    Last - Modified : Fri, 18 Jul 2014 08 : 36 : 36 GMT
    Connection : close

#include <stdio.h>
    int main(void)
{
    printf("hello world!\n");
    return 0;
}
```

```shell
第一行: 状态行
- HTTP / 1.1 : http协议的版本
- 200 : 状态码
- Ok : 对状态码的描述

第 2 - 9 行 : 响应头(消息报头)
- Content - Type : 服务器给客户端回复的数据块的格式 == http响应第四部分的数据块格式
- text / plain; ==> 纯文本
- charset = iso - 8859 - 1 ==> 数据的字符编码
- iso - 8859 - 1 ==> 不支持中文
- utf8: 支持中文
- Content - Length : 服务器给客户端回复的数据块的长度 == http响应第四部分的数据块字节数
- 对应的value值必须是正确的数值
- 如果不知道数据块的字节数, 可以指定 - 1

第 11 - 16 行 : 服务器给客户端回复的响应数据
```







```c
// 服务器端处理的伪代码
int main()
{
    // 1. 创建监听的fd
    socket();
    // 2. 绑定
    bind();
    // 3. 设置监听
    listen();

    // 4. 创建epoll模型
    epoll_create();
    epoll_ctl();
    // 5. 检测
    while (1)
    {
        epoll_wait();
        // 监听的文件描述符
        accept();
        // 通信的
        // 接收数据->http请求消息
        recvAndParseHttp();
    }
    return 0;
}

// 基于边沿非阻塞模型接收数据
int recvAndParseHttp()
{
    // 循环接收数据
    // 解析http请求消息
    // http请求由两种:get / post
    // 只处理get请求, 浏览器向服务器请求访问的文件都是静态资源, 因此使用get就可以
    // 判断是不是get请求  ==> 在请求行中 ==> 请求行的第一部分
    // 客户端向服务器请求的静态资源是什么? => 请求行的第二部分
    // 找到服务器上的静态资源
    -文件->读文件内容
        - 目录->遍历目录
        // 将文件内容或者目录内容打包到http响应协议中
        // 将整条协议发送回给客户端即可
}
```









# 4. 相关操作函数

- ## sscanf函数

```c
// 函数原型
// 将参数str的字符串根据参数format字符串来转换并格式化数据，转换后的结果存于对应的参数内。
sscanf(const char* str, const char* format, ...)。

具体功能如下：
（1）根据格式从字符串中提取数据。如从字符串中取出整数、浮点数和字符串等。
（2）取指定长度的字符串
（3）取到指定字符为止的字符串
（4）取仅包含指定字符集的字符串
（5）取到指定字符集为止的字符串

// 可以使用正则表达式进行字符串的拆分
// shell脚本的时候, 会将正则表达式, 其实就是字符串的匹配规则, 用特殊字符来描述一类字符串
/*
正则匹配规则:
  [1-9]: 匹配一个字符, 这个字符在 1-9 范围内就满足条件
  [2-7]: 匹配一个字符, 这个字符在 2-7 范围内就满足条件
  [a-z]: 匹配一个字符, 这个字符在 a-z 范围内就满足条件
  [A,b,c,D, e, f]: 匹配一个字符, 这个字符是集合中任意一个就满足条件
  [1-9, f-x]: 匹配一个字符, 这个字符是1-9, 或者f-x 集合中的任意一个就满足条件
  [^1]: ^代表否定, 匹配一个字符,这个字符只要不是1就满足条件
  [^2-8]: 匹配一个字符,这个字符只要不在 2-8 范围内就满足条件
  [^a-f]: 匹配一个字符,这个字符只要不在 a-f 范围内就满足条件
  [^ ]: 匹配一个字符,这个字符只要不是空格就满足条件
使用正则表达式如何取匹配字符串:
举例:
  字符串 ==> abcdefg12345AABBCCDD890
  正则表达式: [1-9][a-z], 可以匹配两个字符
  匹配方式: 从原始字符串开始位置遍历, 每遍历一个字符都需要和正则表达式进行匹配,
      满足条件继续向后匹配, 不满足条件, 匹配结束
      从新开始: 从正则表达式的第一个字符重新开始向后一次匹配
          当整个大字符串被匹配一遍, 就结束了
  abcdefg12345AABBCCDD893b
      - 匹配到一个子字符串: 3b
  1a2b3c4d5e6f7g12345AABBCCDD893b
   - 1a
   - 2b
   - 3c
   - 4d
   - 5e
   - 6f
   - 7g
   - 3b
*/
sscanf可以支持格式字符 % []：

(1) - : 表示范围，如： % [1 - 9]表示只读取1 - 9这几个数字 % [a - z]表示只读取a - z小写字母，类似地 % [A - Z]只读取大写字母
(2) ^ : 表示不取，如： % [^ 1]表示读取除'1'以外的所有字符 % [^ / ]表示除 / 以外的所有字符
(3), : 范围可以用","相连接 如 % [1 - 9, a - z]表示同时取1 - 9数字和a - z小写字母
(4)原则：从第一个在指定范围内的数字开始读取，到第一个不在范围内的数字结束 % s 可以看成 % [] 的一个特例 % [^](注意^ 后面有一个空格！)
```

```c
const char* s = "http://www.baidu.com:1234";
char protocol[32] = { 0 };
char host[128] = { 0 };
char port[8] = { 0 };
sscanf(s, "%[^:]://%[^:]:%[1-9]", protocol, host, port);

printf("protocol: %s\n", protocol);
printf("host: %s\n", host);
printf("port: %s\n", port);

///////////////
sscanf("123456 abcdedf", "%[^ ]", buf);
printf("%s\n", buf);
结果为：123456
///////////////
sscanf("123456abcdedfBCDEF", "%[1-9，a-z]", buf);
printf("%s\n", buf);
结果为：123456abcdedf
///////////////
sscanf("123456abcdedfBCDEF", "%[^A-Z]", buf);
printf("%s\n", buf);
结果为：123456abcdedf

```

