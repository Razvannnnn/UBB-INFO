package Repository.File;

import Domain.Entity;
import Domain.Validators.Validator;
import Domain.Validators.ValidatorException;
import Repository.Memory.InMemoryRepository;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public abstract class AbstractFileRepository<ID, E extends Entity<ID>> extends InMemoryRepository<ID, E> {
    private String filename;

    /**
     * Constructor pentru clasa AbstractFileRepository
     * @param validator - validatorul pentru entitatea de tip E
     * @param filename - numele fisierului
     */
    public AbstractFileRepository(Validator<E> validator, String filename) {
        super(validator);
        this.filename = filename;
        readFromFile();
    }

    /**
     * Creaza o entitate dintr-o linie
     * @param line - linia din fisier
     * @return entitatea creata
     */
    public abstract E createEntity(String line);

    /**
     * Salveaza o entitate intr-un string
     * @param entity - entitatea de salvat
     * @return stringul in care a fost salvata entitatea
     */
    public abstract String saveEntity(E entity);

    @Override
    public E findOne(ID id) {
        return super.findOne(id);
    }

    @Override
    public Iterable<E> findAll() {
        return super.findAll();
    }

    @Override
    public E save(E entity) throws ValidatorException {
        E e = super.save(entity);
        if(e == null) {
            writeToFile();
        }
        return e;
    }

    /**
     * Citeste entitatile din fisier
     */
    public void readFromFile() {
        try (BufferedReader reader = new BufferedReader(new java.io.FileReader(filename))) {
            String line;
            while ((line = reader.readLine()) != null) {
                E entity = createEntity(line);
                super.save(entity);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * Scrie entitatile in fisier
     */
    public void writeToFile() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            for(E entity: entities.values()) {
                String ent = saveEntity(entity);
                writer.write(ent);
                writer.newLine();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public E delete(ID id) {
        E e = super.delete(id);
        if(e != null) {
            writeToFile();
        }
        return e;
    }

    @Override
    public E update(E entity) {
        return super.update(entity);
    }
}
