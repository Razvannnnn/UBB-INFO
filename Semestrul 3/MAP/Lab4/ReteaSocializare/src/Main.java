import Domain.Prietenie;
import Domain.Utilizator;
import Domain.Validators.PrietenieValidator;
import Domain.Validators.UtilizatorValidator;
import Repository.File.PrieteniiRepository;
import Repository.File.UtilizatorRepository;
import Repository.Memory.InMemoryRepository;
import Service.Network;
import UI.console;

import java.io.Console;

public class Main {
    public static void main(String[] args) {
        /*
        InMemoryRepository<Long, Utilizator> repositoryUtilizator = new InMemoryRepository<>(new UtilizatorValidator());
        InMemoryRepository<Long, Prietenie> repositoryPrietenie = new InMemoryRepository<>(new PrietenieValidator(repositoryUtilizator));
        */

        UtilizatorRepository utilizatorRepository = new UtilizatorRepository(new UtilizatorValidator(), "C:\\Users\\razva\\Desktop\\MAP\\Lab4\\ReteaSocializare\\src\\Repository\\File\\utilizatori.txt");
        PrieteniiRepository prieteniiRepository = new PrieteniiRepository(new PrietenieValidator(utilizatorRepository), "C:\\Users\\razva\\Desktop\\MAP\\Lab4\\ReteaSocializare\\src\\Repository\\File\\prietenii.txt");

        Network network = new Network(utilizatorRepository, prieteniiRepository);

        console console = new console(network);
        console.run();
    }
}