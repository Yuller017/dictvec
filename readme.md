# 说明


## 基本运算

设 `a = {"aa":0.1, "bb":0.2, "cc":0.3}, b = {"aa":1, "be":2, "cc":3}`.


### 乘法

基失取交集，值相乘

```
c = a * b
  = {"aa":0.1, "cc":0.9}
```

### 加法

基失取并集，指相加
```
d = a + b
  = {"aa":1.1, "bb":0.2, "be":2, "cc":3.3}
```

### 数乘

基失不变，值相乘
```
2 * a = {"aa":0.2, "bb":0.4, "cc":0.6}
```

## 其他操作
...
