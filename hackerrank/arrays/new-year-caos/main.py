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
Solução:
1. - Faremos um loop que irá verificar cada elemento de trás para frente. Do último elemento da lista, até o primeiro.
1.2 - para cada elemento, verificar se valor diferente de i+1 (se valor é diferente de i+1, o elemento não está na posição correta)
1.3 - se o elemento está fora de sua posição original, verificar se o elemento anterior é o elemento correto da posição que estamos verificando (e.g posição 7, elemento original é 8)
1.3.1 - se o elemento anterior é o correto, adicionar um suborno à contagem e rearrumar a fila.
1.4 - se o elemento está fora de sua posição original e o elemento anterior não é o elemento correto da posição, verificar se o segundo elemento anterior é o elemento correto
1.4.1 - se o segundo elemento anterior é o correto, adicionar 2 subornos à contagem e rearrumar a fila
1.5 - se 1.3 e 1.4 são falsos, isso indica que o elemento quebrou a primeira premissa. (um elemento só pode andar 2 posições), logo a fila é caótica, encerra o programa.

Exemplo prático 1:
Fila: 1 2 3 5 4 6 7 8
Primeira Iteração: i=7, passo 1.2 -> i+1 = 8, q[7] = 8. Continua o Loop.
Segunda Iteração: i=6, passo 1.2 -> i+1 = 7, q[6] = 7. Continua o Loop.
Terceira Iteração: i=5, passo 1.2 -> i+1=6, q[5] = 6. Continua o Loop.
Quarta Iteração: i=4, passo 1.2 -> i+1=5, q[4] = 4. q[4] != 5, vai para 1.3
1.3 -> i-1=3 e q[3] = i+1 = 5, vai para 1.3.1
1.3.1 -> Soma-se 1 ao número de Subornos, numBribes=1
1.3.1 -> Arruma a fila -> 1 2 3 4 5 6 7 8. Continua o Loop.
Quinta Iteração: i=3, passo 1.2 -> i+1 = 4, q[3] = 4. Continua o Loop.
Sexta Iteração: i=2, passo 1.2 -> i+1 = 3, q[2] = 3. Continua o Loop.
Sétima Iteração: i=1, passo 1.2 -> i+1 = 2, q[2] = 2. Continua o Loop.

Fim da Iteração: Retorna o número de subornos. numBribes=1.

Exemplo prático 2:
Fila: 1 2 5 3 7 8 6 4
Primeira Iteração: i=7, passo 1.2 -> i+1 = 8, q[7] = 4. q[7] != 8, vai para 1.3
1.3 -> i-1=6 e q[6] = 6 != i+1, vai para 1.4
1.4 -> i-2=5 e q[5] = 8 = i+1, vai para 1.4.1
1.4.1 -> Soma-se 2 ao número de Subornos, numBribes=2
1.4.1 -> Arruma-se a fila, q[i-2] = q[5] = 6, q[i-1] = q[6] = 4, q[7] = 8.
1.4.1 -> Nova Fila: 1 2 5 3 7 6 4 8. Continua o Loop.

Nova Fila: 1 2 5 3 7 6 4 8
Segunda Iteração: i=6, passo 1.2 -> i+1 = 7, q[6] = 4. q[6] != 7, vai para 1.3
1.3 -> i-1=5 e q[5] = 6 != i+1 = 7, vai para 1.4
1.4 -> i-2=4 e q[4] = 7 = i+1, vai para 1.4.1
1.4.1 -> Soma-se 2 ao número de Subornos, numBribes=4
1.4.1 -> Arruma-se a fila, q[i-2] = q[4] = 6.: q[i-1] = q[5] = 4.: q[6] = 7.
1.4.1 -> Nova Fila: 1 2 5 3 6 4 7 8. Continua o Loop.

Nova Fila: 1 2 5 3 6 4 7 8
Terceira Iteração: i=5, passo 1.2 -> i+1 = 6, q[5] = 4. q[5] != 6, vai para 1.3
1.3 -> i-1=4, q[4] = 6 = i+1, vai para 1.3.1
1.3.1 -> Soma-se 1 ao número de Subornos, numBribes=5
1.3.1 -> Arruma-se a fila, q[5] = 6, q[4] = 4.
1.3.1 -> Nova Fila: 1 2 5 3 4 6 7 8. Continua o Loop.

Nova Fila: 1 2 5 3 4 6 7 8
Quarta Iteração: i=4, passo 1.2 -> i+1 = 5, q[4] = 4. q[4] != 5, vai para 1.3
1.3 -> i-1=3, q[3] = 3 != i+1, vai para 1.4
1.4 -> i-2=2, q[2] = 5 = i+1, vai para 1.4.1
1.4.1 -> Soma-se 2 ao número de Subornos, numBribes=7
1.4.1 -> Arruma-se a fila, q[i-2] = q[2] = 3.: q[i-1] = q[3] = 4.: q[i] = q[4] = 5.
1.4.1 -> Nova Fila: 1 2 3 4 5 6 7 8. Continua o Loop.

1.4.1 -> Nova Fila: 1 2 3 4 5 6 7 8
Quinta Iteração: i=3, passo 1.2 -> i+1 = 4, q[3] = 4. Continua o Loop.
Sexta Iteração: i=2, passo 1.2 -> i+1 = 3, q[2] = 3. Continua o Loop.
Sétima Iteração: i=1, passo 1.2 -> i+1 = 2, q[2] = 2. Continua o Loop.
Fim da Iteração: Retorna o número de subornos. numBribes=7.
'''

def minimumBribes(q):
	numBribes = 0
	# Loop do último elemento até o primeiro (e.g lista com 8 elemento, da posição 7 até a 0)
	for i in range(len(q)-1, 0, -1):
		# Verificar se o elemento está fora de sua posição original
		if q[i] != (i+1):
			# Verificar que não está indo além da lista (i-1>=0) e verificar se o elemento anterior é o elemento correto da posição
			if (i-1) >= 0 and q[i-1] == (i+1):
				# adicionar um suborno à contagem
				numBribes += 1
				# rearrumar a fila
				q[i], q[i-1] = q[i-1], q[i]
			# Verificar que não está indo além da lista (i-2>=0) e verificar se o segundo elemento anterior é o elemento correto da posição
			elif (i-2) >= 0 and q[i-2] == (i+1):
				# adicionar 2 subornos à contagem
				numBribes +=2
				# arruma a fila colocando o elemento anterior no lugar do segundo anterior
				q[i-2] = q[i-1]
				# arruma a fila colocando o elemento verificado no lugar do anterior
				q[i-1] = q[i]
				# arruma a fila colocando o elemento certo em sua posição
				q[i] = i+1
			else:
				# elemento andou mais que 2 posições, a fila é considerada caótica. Encerra a função
				print("Too chaotic")
				return
	print(numBribes)
	return

