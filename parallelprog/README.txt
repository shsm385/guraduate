セミナーD におけるレポート課題

openmp と MPI の入れ方

1 xcodeで入れてる gcc だと動かないので gcc の対応しているものを MacPorts か brew で入れる
2 これで openmp は使える
3 mpi を使いたい場合には openmpi を取ってきて突っ込む
4 mpi が使えるようになる

詳細はここに書いておくのでみてどうぞ
http://shsm385.hatenablog.com/

逐次のソース: pi.c
並列(OpneMP(1)) : pi_openmp.c
並列(OpneMP(2) : pi_openmp2.c
並列(MPI) : pi_MPI.c)


課題内容
πの計算
1) 逐次のソース 実行結果 (時間も
2) 並列版のソース 実行結果 (時間も
3) 実行結果が一意に定まらない場合、理由を考察および、実行結果が同一で無い場合、理由を考察
4) 分割数を色々変えて、実行結果の違いを見る。
5) コア数と2)/1)の時間比との関係を考察する

メイルで地の文、PDF、MS-Word互換ファイル(後者の２つは添付で良い)を提出
