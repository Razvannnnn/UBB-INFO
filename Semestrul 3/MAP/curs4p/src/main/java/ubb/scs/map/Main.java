package ubb.scs.map;

import ubb.scs.map.domain.Utilizator;
import ubb.scs.map.domain.validators.UtilizatorValidator;
import ubb.scs.map.repository.Repository;

import ubb.scs.map.repository.database.UtilizatorDbRepository;

import java.util.List;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {

//        Repository<Long, Utilizator> repo = new InMemoryRepository<Long, Utilizator>(new UtilizatorValidator());
//        Repository<Long, Utilizator> repoFile = new UtilizatorRepository(new UtilizatorValidator(), "./data/utilizatori.txt");
//        Utilizator u1 = new Utilizator("IONUT", "a");
//        Utilizator u2 = new Utilizator("Mihai", "b");
//        Utilizator u3 = null;
//        u1.setId(1L);
//        u2.setId(2L);
//        try {
//            repoFile.save(u1);
//            repoFile.save(u2);
//            repoFile.save(u3);
//        }catch(IllegalArgumentException e)
//        {
//            System.out.println(e.getMessage());
//        }catch(ValidationException e)
//        {
//            System.out.println(e.getMessage());
//        }
//        System.out.println();

        String username="postgres";
        String pasword="postgres";
        String url="jdbc:postgresql://localhost:5436/socialnetwork";
        Repository<Long,Utilizator> userFileRepository3 =
            new UtilizatorDbRepository(url,username, pasword,  new UtilizatorValidator());

       // userFileRepository3.save(new Utilizator("XXY", "YYY"));
        userFileRepository3.findAll().forEach(x-> System.out.println(x));
//        Iterable<Utilizator> users = userFileRepository3.findAll();

    }
}