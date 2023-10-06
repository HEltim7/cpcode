牌组有81个卡牌，每个卡牌有4个特征，每个特征分为3个子类，分别是

- 数量 [one,two,three]
- 形状 [diamond,squiggle,oval]
- 阴影 [solid,striped,open]
- 颜色 [red,green,purple]

卡牌的特征两两不同，即 $3^4=81$。

称三张卡牌构成set,当且仅当这三张牌的每种特征都满足：

- 全都相同
- 全都不同

另有一些百搭牌，包含一种或多种特征通配符，例如 [*][diamond][solid][red]。

问题：给定 $n$ 张卡牌，找出任意的一组合法set。