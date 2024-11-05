Algoritmo "pagamento"

var
                            nome : caractere
                            horaTrabalhada, valor, quantidade : real


inicio


      escreva("Digite o nome do funcionário: ")
      leia(nome)
      escreva("Digite o valor da hora trabalhada: ")
      leia(horaTrabalhada)
      escreva("Digite a quantidade de horas trabalhadas: ")
      leia(quantidade)
      
                      valor <- horaTrabalhada * quantidade
                      
                            escreval("Nome do funcionário: ", nome)
                            escreval("Horas trabalhadas: ", quantidade)
                            escreval("Valor da hora: ", horaTrabalhada)
                            escreva("O pagamento para ", nome, " deve ser: ", valor)

Fimalgoritmo