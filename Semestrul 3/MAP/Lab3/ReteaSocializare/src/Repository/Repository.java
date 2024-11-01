package Repository;

import Domain.Entity;

public interface Repository<ID, E extends Entity<ID>> {
    /**
     * Functie care returneaza entitatea cu id-ul dat
     * @param id - id-ul entitatii care trebuie returnata
     * @return entitatea cu id-ul dat sau null daca nu exista entitatea cu id-ul dat
     */
    E findOne(ID id);

    /**
     * Functie care returneaza toate entitatile
     * @return toate entitatile
     */
    Iterable<E> findAll();

    /**
     * Functie care salveaza o entitate
     * @param entity - entitatea care trebuie salvata
     * @return null daca entitatea a fost salvata cu succes, altfel entitatea
     */
    E save(E entity);

    /**
     * Functie care sterge o entitate
     * @param id - id-ul entitatii care trebuie stearsa
     * @return entitatea stearsa sau null daca nu exista entitatea cu id-ul dat
     */
    E delete(ID id);

    /**
     * Functie care actualizeaza o entitate
     * @param entity - entitatea care trebuie actualizata
     * @return null daca entitatea a fost actualizata cu succes, altfel entitatea
     */
    E update(E entity);
}
