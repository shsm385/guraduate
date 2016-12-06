/*man or women*/
man(uranos).
man(kronos).
man(poseidon).
man(zeus).
man(hades).
man(apollon).
man(asklepios).
woman(gaia).
woman(rhea).
woman(hestia).
woman(demeter).
woman(here).
woman(leto).
woman(artemis).
woman(koronis).

/*father*/
father(uranos,kronos).
father(kronos,hestia).
father(kronos,demeter).
father(kronos,here).
father(kronos,haddes).
father(kronos,poseidon).
father(kronos,zeus).
father(zeus,apollon).
father(zeus,artemis).
father(apollon,askleios).

/*mother*/
mother(gaia,kronos).
mother(rhea,hestia).
mother(rhea,demeter).
mother(rhea,here).
mother(rhea,haddes).
mother(rhea,poseidon).
mother(rhea,zeus).
mother(leto,apollon).
mother(leto,artemis).

/*parent*/
parents(X,Y) :- father(X,Y).
parents(X,Y) :- mother(X,Y).

/*child*/
child(X,Y) :- parents(Y,X),man(X).
child(X,Y) :- parents(Y,X),woman(X).

/*son*/
son(X,Y) :- parents(Y,X),man(X).

/*daughter*/
daughter(X,Y) :- parents(Y,X),woman(X).

/*grandfather*/
grandfather(X,Y) :- parents(Z,Y),father(X,Z).

/*grandmother*/
grandmother(X,Y) :- parents(Z,Y),mother(X,Z).

/*sister*/
sister(X,Y) :- parents(Z,X),parents(Z,Y),woman(X),woman(Y).

/*brother*/
brother(X,Y) :- parents(Z,X),parents(Z,Y),man(X),man(Y).

/*siblings*/
siblings(X,Y) :- parents(Z,X),parents(Z,Y).

/*descendants*/
descendants(X,Y) :- parents(Y,Z),descendants(X,Z).
descendants(X,Y) :- parents(Y,X).

/*ancester*/
ancester(X,Y) :- child(Y,Z),ancester(X,Z).
ancester(X,Y) :- child(Y,X).


/**
・アルテミスはクロノスの子孫である
実行例
?- descendants(artemis,kronos).
実行結果
true.

・ウラノスはコロニスの祖先ではない
実行例
\+ ancester(uranos,koronis).
実行結果
true.

・アポロンの先祖をすべて知りたい
実行例
?- ancester(X,apollon).
実行結果
X = uranos ; 
X = gaia ;
X = kronos ;
X = rhea ;
X = zeus ;
X = leto ;
**/
