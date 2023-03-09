# countwords

count words

https://benhoyt.com/writings/count-words/

编译命令：

```bash
g++ -std=c++20 count.cpp

rustc count.rs

go build count.go
```


运行测试：

```bash
./a.out kjvbible.txt

./count kjvbible.txt

./count kjvbible.txt

python3 count.py kjvbible.txt
```


测试环境：

- x86_64 Linux 5.15.90.1-microsoft-standard-WSL2
- openSUSE Tumbleweed(on the Windows Subsystem for Linux)
- 12th Gen Intel Core i7-12700H @ 20x 2.688GHz

对比：

运行 kjvbible.txt

| 程序 | 运行时间 |
| ---- | ---- |
| CPP | 0.46s |
| Rust | 0.32s |
| Go | 0.09s |
| Python | 0.19s |


运行 big.txt

| 程序 | 运行时间 |
| ---- | ---- |
| CPP | 47.63s |
| Rust | 38.46s |
| Go | 6.24s |
| Python | 13.26s |


继续优化，并添加大样本。