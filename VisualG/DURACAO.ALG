Algoritmo "duracao"

var

   horas, minutos, segundos : inteiro


inicio
           escreva("Digite a dura��o: ")
           leia(segundos)

                        horas <- segundos / 3600
                        minutos <- (segundos mod 3600) /60
                        segundos <- segundos mod 60
                        
                        
                        escreva("Em horas s�o:",horas,":", minutos,":", segundos)
Fimalgoritmo