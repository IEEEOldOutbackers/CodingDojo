'''
Coding Dojo 2020 - Python
Exercise: New Year Chaos
Link: https://www.hackerrank.com/challenges/new-year-chaos/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
It's New Year's Day and everyone's in line for the Wonderland rollercoaster ride!
There are a number of people queued up, and each person wears a sticker indicating their initial position in the queue.
Initial positions increment by from at the front of the line to n at the abck.
Any person in the queue can bribe the person directly in front of them to swap positions.If two people swap positions,
they still wear the same sticker denoting their original places in line.One person can bribe at most two others.
For example, if n=8 and Person 5 bribes Person 4, the queue will look like this : 1,2,3,5,4,6,7,8
Fascinated by this chaotic queue, you decide you must know the minimum number of bribes that took place to
get the queue into its current state !
Premissa:
1 - Cada pessoa (valor) só pode andar 2 casas (posições)
2 - Temos algarismos consecutivos começando em 1
3 - As propinas só conta para o número que avança na fila (avança para o lado esquerdo)
4 - 
'''


def minimumBribes(Q):

    # Número de propinas feitas
    bribes = 0

    # Percorrendo a fila, obtendo o número da pessoa e sua posição na fila
    for position, num_person in enumerate(Q):

        # Se o "número da pessoa" menos "sua posição na fila" for maior que 3 <TOO CHAOTIC>
        if num_person - position > 3:
            print("Too chaotic")
            return
        # Verifica se há numero maior em sua frente
        for j in range(max(num_person - 2, 0), position):
            if Q[j] > num_person:
                bribes += 1
    print(bribes)


if __name__ == "__main__":

    lista = '1 2 5 3 7 8 6 4'
    lista = lista.split()
    lista = list(map(int, lista))
    minimumBribes(lista)
