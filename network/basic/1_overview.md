# 计算机网络

计算机网络：自顶向下方法（原书第6版）

## 总览

- 什么是端系统/主机 (P.7)
- 端系统怎么连接到一起的 (P.3)
  - 什么是通信链路
  - 什么是分组交换机
- 2种最出名的分组交换机(packet switch) (P.3)
- 通过网络的路径(route, path)是什么 (P.3)
- 端系统怎么接入因特网的 (P.3)
- 什么是ISP? 有什么作用? (P.3)
- 协议的定义 (P.6)
- 什么是接入网(access network) (P.7)
- 什么是边缘路由器(edge router) (P.7)
- 列举不同的接入方式 (P.8-P.13)
- 物理媒体有哪几类 (P.14)
- 报文的简单定义 (P.16, 35)
- 分组的简单定义 (P.16)
- [存储转发传输(store-and-forward transmission)](record/1_store_and_forward_transmission.md) (P.16)
  - 定义 (P.17)
  - 起源
  - 应用场景
  - 举例说明 (P.17)
  - P个分组通过N条速率为R的链路（N - 1台交换机）的端到端时延多少?
- 输出缓存/队列存储的是什么？(P.17)
- 什么是排队时延？(P.17)
  - **解决办法？**
- 什么是分组丢失(丢包)? (P.18)
  - **解决办法？**
- 转发表的作用 (P.18)
  - **细节？**
- 通过网络链路和交换机移动数据的两种方法？(P.19)
- 电路交换和分组交换的主要区别 (P.19)
- 频分复用(Frequency-Division Multiplexing, FDM)的特点(P.19)
- 频分复用中的带宽指什么(P.19)
- 时分复用(Time-Division Multiplextin, TDM)的原理是什么(P.19)
- 电路交换缺点(P.19)
- 已知每个用户活跃概率为p，总共有n个用户，则实际有k个用户活跃的概率是多少？(二项式分布)
- 时延
  - 时延有哪些类型？(P.25)
  - 处理时延是什么？(P.26)
  - 传输时延是什么？(P.26)
  - 传播时延是什么？(P.26)
  - 处理时延会影响到路由器的哪方面性能？(P.27)
  - 什么是流量强度？流量强度大于1会发生什么？(P.28)
- 分层协议
  - 五层因特网协议栈是什么？(P.35)
  - 七层ISO OSI参考模型是什么？(P.35)
  - 不同层次负责的数据/信息分组叫什么？(P.35,36)
  - 表示层和会话层的功能是什么？(P.36)
  - 链路层交换机和路由器分别实现了哪几层网络的协议？(P.37)
  - 每一层分组的组成(概括描述)(P.38)
