- 在进程间通信会话的场景中，客户和服务器定义分别是什么？(P.59)
- P2P中客户和服务器的定义分别是什么？(P.59)
- 应用程序进程和运输层协议之间的接口是什么？(P.59)
  - **只有一个接口吗？**
- 进程寻址时如何标识接收进程的地址？(P.59)
  - 怎么标识主机？(P.60)
  - 怎么标识接收进程？(P.60)
- 运输层协议可以为调用它的应用程序提供哪几种服务？(P.60)
- TCP主要提供哪两种服务？简略描述(P.62)
  - TCP连接是全双工的是什么意思
- UDP与TCP相比有什么不同(P.63)
- 应用层协议的作用(P.64)
- 非持续连接和持续连接是什么？(P.67)
- 非持续连接的缺点是什么？(P.69)
- 往返时间(Round-Trip Time, RTT)指什么？(P.68)
- HTTP
  - 为什么说HTTP是一个无状态协议？(P.67)
  - **从输入url到收到web页面的过程简述**(P.67)
  - HTTP请求报文的组成？(P.69)
    - 请求行字段(P.69)
    - 首部行组成(P.69)
    - 为什么有了TCP连接还要在首部行中指定主机？
  - [HTTP报文](https://developer.mozilla.org/zh-CN/docs/Web/HTTP/Messages)
  - [HTTP 1.x - 2](https://www.digitalocean.com/community/tutorials/http-1-1-vs-http-2-what-s-the-difference)
  - cookie的作用(P.74)
    - [Cookie HTTP request header](https://developer.mozilla.org/zh-CN/docs/Web/HTTP/Headers/Cookie)
    - [HTTP cookies](https://developer.mozilla.org/zh-CN/docs/Web/HTTP/Cookies)
- 什么是Web缓存器(Web cache)或代理服务器(proxy server)？简述工作流程(P.74)
  - web缓存器的优点(P.75)
  - **什么时候用Web缓存器？缓存是针对的单用户还是多用户？如何保证缓存的对象是最新的？**
    - **流量强度**解释应用场景
    - [HTTP条件请求](https://developer.mozilla.org/zh-CN/docs/Web/HTTP/Conditional_requests)
  - **了解内容分发网络(Content Distribution Network, CDN)**
