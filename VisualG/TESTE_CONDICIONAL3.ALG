Algoritmo "teste_condicional3"

Var
   hora: inteiro

Inicio

      escreva("Digite uma hora do dia: ")
      leia(hora)
      
                se hora < 12 entao
                   escreval("Bom dia! ")
                   fimse

                        se (hora >= 12) e (hora < 10) entao
                           escreval("Boa Tarde! ")
                                         fimse
                                         
                                              se hora > 18 entao
                                                 escreval("Boa noite! ")
                                                               fimse
                                         

Fimalgoritmo