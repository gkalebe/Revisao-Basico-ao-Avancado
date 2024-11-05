Algoritmo "retangulo"

var
            area, base, altura : real
            diagonal, perimetro: real

Inicio

             escreva("Digite a altura: ")
             leia(altura)
             escreval("Digite a base: ")
             leia(base)

                       area <- base * altura
                       
                            escreval("O valor da área é: ", area:8:4)
                            
                            perimetro <- 2 * (base + altura)
                            
                            escreval("O valor do perimetro é: ", perimetro:8:4)
                            
                            
                                        diagonal <- RaizQ (Exp(base, 2) + Exp(altura, 2))
                                        
                                                 escreval("O valor da diagonal é: ", diagonal:8:4)


Fimalgoritmo