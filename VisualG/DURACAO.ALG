Algoritmo "duracao"

var

   horas, minutos, segundos : inteiro


inicio
           escreva("Digite a duração: ")
           leia(segundos)

                        horas <- segundos / 3600
                        minutos <- (segundos mod 3600) /60
                        segundos <- segundos mod 60
                        
                        
                        escreva("Em horas são:",horas,":", minutos,":", segundos)
Fimalgoritmo