package ubb.scs.map.repository.file;

import ubb.scs.map.domain.Entity;
import ubb.scs.map.domain.validators.Validator;
import ubb.scs.map.repository.memory.InMemoryRepository;

import java.io.*;

public abstract class AbstractFileRepository<ID, E extends Entity<ID>> extends InMemoryRepository<ID, E>{
    private String filename;

    public AbstractFileRepository(Validator<E> validator, String fileName) {
        super(validator);
        filename=fileName;
    }


    public abstract E lineToEntity(String line);
    public abstract String entityToLine(E entity);
    @Override
    public E findOne(ID id) {
        return null;
    }

    @Override
    public Iterable<E> findAll() {
        return null;
    }

    @Override
    public E save(E entity) {
        E e = super.save(entity);
        if (e == null)
            writeToFile();
        return e;
    }

    private void writeToFile() {

        try  ( BufferedWriter writer = new BufferedWriter(new FileWriter(filename))){
            for (E entity: entities.values()) {
                String ent = entityToLine(entity);
                writer.write(ent);
                writer.newLine();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }

    private void writeToFile(E entity) {
        try  ( BufferedWriter writer = new BufferedWriter(new FileWriter(filename, true))){
            writer.write(entityToLine(entity));
            writer.newLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private void lineData() {
        try (BufferedReader bufferedReader = new BufferedReader(new FileReader(filename))) {
            String line = bufferedReader.readLine();
            while (line != null) {
                E entity = lineToEntity(line);
                super.save(entity);
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public E delete(ID id) {
        E entity = super.delete(id);
        if(entity != null) {
            writeToFile();
        }
        return entity;
    }

    @Override
    public E update(E entity) {
        E entityc = super.update(entity);
        if(entityc == null) {
            writeToFile();
        }
        return entityc;
    }
}
