package produtos;

public class Vestuario extends Produto {
    
    private String tamanho;

   
    public Vestuario(String codigo, String nome, double preco, int quantidade, String tamanho) {
        super(codigo, nome, preco, quantidade);
        this.tamanho = tamanho;
    }

   
    @Override
    public void exibirInformacoes() {
        System.out.println("Tipo: Vestuário");
        System.out.println("Código: " + getCodigo());
        System.out.println("Nome: " + getNome());
        System.out.println("Preço: " + getPreco());
        System.out.println("Quantidade: " + getQuantidade());
        System.out.println("Tamanho: " + tamanho);
    }

	public String getTamanho() {
		return tamanho;
	}

	public void setTamanho(String tamanho) {
		this.tamanho = tamanho;
	}
}