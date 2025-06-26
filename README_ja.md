# 仮想LEDコントローラ（C言語）

## 概要
8個のLEDのON/OFF状態をコマンドラインから操作できるC言語プログラムです。
LEDの状態はファイルに保存・読み込みができます。

## 特徴・できること
- LEDのON/OFF制御
- 全LED状態の表示
- 状態をファイル保存・復元
- 入力エラー処理
- シンプルなコマンドUI

## 操作方法

| コマンド | 説明 |
|:--------:|:-----|
| `on`     | 指定したLED（0-7）をON |
| `off`    | 指定したLED（0-7）をOFF |
| `show`   | 現在のLED状態を表示 |
| `save`   | 状態をファイルに保存 |
| `load`   | ファイルから状態を復元 |
| `exit`   | 終了 |

### 実行例
```sh
Enter command: on
Enter LED number (0-7): 3
LED 3 turned ON
Enter command: show
Current LED states: 0 0 0 1 0 0 0 0
Enter command: save
LED states saved to led_control.txt
Enter command: exit
