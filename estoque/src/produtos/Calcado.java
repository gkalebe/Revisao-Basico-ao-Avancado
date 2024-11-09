package produtos;

public class Calcado extends Produto {
    
    private int numero;

  
    public Calcado(String codigo, String nome, double preco, int quantidade, int numero) {
        super(codigo, nome, preco, quantidade);
        this.numero = numero;
    }

    
    @Override
    public void exibirInformacoes() {
        System.out.println("Tipo: Calçado");
        System.out.println("Código: " + getCodigo());
        System.out.println("Nome: " + getNome());
        System.out.println("Preço: " + getPreco());
        System.out.println("Quantidade: " + getQuantidade());
        System.out.println("Número: " + numero);
    }

	public int getNumero() {
		return numero;
	}

	public void setNumero(int numero) {
		this.numero = numero;
	}
}