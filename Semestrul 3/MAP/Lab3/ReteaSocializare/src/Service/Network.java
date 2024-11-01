package Service;

import Domain.*;
import Repository.File.PrieteniiRepository;
import Repository.File.UtilizatorRepository;
import Repository.Memory.InMemoryRepository;

import java.util.Vector;

public class Network {
    /*
    private final InMemoryRepository<Long, Utilizator> repositoryUtilizator;
    private final InMemoryRepository<Long, Prietenie> repositoryPrietenie;
    */
    private final UtilizatorRepository repositoryUtilizator;
    private final PrieteniiRepository repositoryPrietenie;

    /**
     * Constructor pentru clasa Network
     * @param repositoryUtilizator
     * @param repositoryPrietenie
     */
    public Network(UtilizatorRepository repositoryUtilizator, PrieteniiRepository repositoryPrietenie) {
        this.repositoryUtilizator = repositoryUtilizator;
        this.repositoryPrietenie = repositoryPrietenie;
    }

    public Iterable<Utilizator> getUtilizatori() {
        return repositoryUtilizator.findAll();
    }

    public Iterable<Prietenie> getPrietenii() {
        return repositoryPrietenie.findAll();
    }

    public Utilizator findUtilizator(Long id) {
        return repositoryUtilizator.findOne(id);
    }

    public Prietenie findPrietenie(Long id) {
        return repositoryPrietenie.findOne(id);
    }


    /**
     * Metoda care returneaza un id pentru un utilizator nou
     * @return id-ul utilizatorului
     */
    public Long getNewUtilizatorID() {
        Long id = 0L;
        if(repositoryUtilizator.findAll() != null) {
            for(Utilizator utilizator : repositoryUtilizator.findAll()) {
                if(utilizator.getId() > id) {
                    id = utilizator.getId();
                }
            }
        }
        id++;
        return id;
    }


    /**
     * Metoda care returneaza un id pentru o prietenie noua
     * @return id-ul prieteniei
     */
    public Long getNewPrietenieID() {
        Long id = 0L;
        if(repositoryPrietenie.findAll() != null) {
            for(Prietenie prietenie : repositoryPrietenie.findAll()) {
                if(prietenie.getId() != null && prietenie.getId() > id) {
                    id = prietenie.getId();
                }
            }
        }
        id++;
        return id;
    }

    /**
     * Metoda care adauga un utilizator in retea
     * @param utilizator - utilizatorul de adaugat
     */
    public void addUtilizator(Utilizator utilizator) {
        utilizator.setId(getNewUtilizatorID());
        repositoryUtilizator.save(utilizator);
    }


    /**
     * Metoda care sterge un utilizator din retea
     * @param id - id-ul utilizatorului de sters
     * @return utilizatorul sters
     */
    public Utilizator removeUtilizator(Long id) {
        try {
            Utilizator u = repositoryUtilizator.findOne(id);
            if(u == null) {
                throw new IllegalArgumentException("Utilizatorul nu exista!");
            }
            Vector<Long> toDelete = new Vector<>();
            for(Prietenie prietenie : repositoryPrietenie.findAll()) {
                if(prietenie.getIdUtilizator1().equals(id) || prietenie.getIdUtilizator2().equals(id)) {
                    toDelete.add(prietenie.getId());
                }
            }
            for(Long idPrietenie : toDelete) {
                repositoryPrietenie.delete(idPrietenie);
            }
            Utilizator utilizator = repositoryUtilizator.delete(id);
            if(u.getPrieteni() != null) {
                for(Utilizator prieten : u.getPrieteni()) {
                    prieten.removePrieten(u);
                }
            }
            return utilizator;
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
        return null;
    }


    /**
     * Metoda care adauga o prietenie in retea
     * @param prietenie - prietenia de adaugat
     */
    public void addPrietenie(Prietenie prietenie) {
        Utilizator utilizator1 = repositoryUtilizator.findOne(prietenie.getIdUtilizator1());
        Utilizator utilizator2 = repositoryUtilizator.findOne(prietenie.getIdUtilizator2());

        if(getPrietenii() != null) {
            for(Prietenie p : getPrietenii()) {
                if((p.getIdUtilizator1().equals(prietenie.getIdUtilizator1()) && p.getIdUtilizator2().equals(prietenie.getIdUtilizator2())) ||
                        (p.getIdUtilizator1().equals(prietenie.getIdUtilizator2()) && p.getIdUtilizator2().equals(prietenie.getIdUtilizator1()))) {
                    throw new IllegalArgumentException("Prietenia exista deja!");
                }
            }
            if(repositoryUtilizator.findOne(prietenie.getIdUtilizator1()) == null || repositoryUtilizator.findOne(prietenie.getIdUtilizator2()) == null) {
                throw new IllegalArgumentException("Unul dintre utilizatori nu exista!");
            }
            if(prietenie.getIdUtilizator1().equals(prietenie.getIdUtilizator2())) {
                throw new IllegalArgumentException("Utilizatorii sunt aceeasi persoana!");
            }
        }
        prietenie.setId(getNewPrietenieID());
        repositoryPrietenie.save(prietenie);

        utilizator1.addPrieten(utilizator2);
        utilizator2.addPrieten(utilizator1);
    }


    /**
     * Metoda care sterge o prietenie din retea
     * @param id1 - id-ul primului utilizator
     * @param id2 - id-ul celui de-al doilea utilizator
     */
    public void removePrietenie(Long id1, Long id2) {
        Utilizator utilizator1 = repositoryUtilizator.findOne(id1);
        Utilizator utilizator2 = repositoryUtilizator.findOne(id2);
        Long id = 0L;
        for(Prietenie prietenie : repositoryPrietenie.findAll()) {
            if((prietenie.getIdUtilizator1().equals(id1) && prietenie.getIdUtilizator2().equals(id2)) ||
                    (prietenie.getIdUtilizator1().equals(id2) && prietenie.getIdUtilizator2().equals(id1))) {
                id = prietenie.getId();
            }
        }
        if(id == 0L) {
            throw new IllegalArgumentException("Prietenia nu exista!");
        }
        repositoryPrietenie.delete(id);
        utilizator1.removePrieten(utilizator2);
        utilizator2.removePrieten(utilizator1);
    }

}
