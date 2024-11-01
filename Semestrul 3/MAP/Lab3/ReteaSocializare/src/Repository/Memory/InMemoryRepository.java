package Repository.Memory;

import Domain.Entity;
import Domain.Utilizator;
import Domain.Validators.Validator;
import Domain.Validators.ValidatorException;
import Repository.Repository;

import java.util.HashMap;
import java.util.Map;

public class InMemoryRepository<ID, E extends Entity<ID>> implements Repository<ID, E> {
    private Validator<E> validator;
    protected Map<ID, E> entities;

    /**
     * Contructor pentru clasa InMemoryRepository
     * @param validator - validatorul pentru entitatea de tip E
     */
    public InMemoryRepository(Validator<E> validator) {
        this.validator = validator;
        entities = new HashMap<ID, E>();
    }

    @Override
    public E findOne(ID id) {
        if(id == null) {
            throw new IllegalArgumentException("ID CANNOT BE NULL!");
        }
        return entities.get(id);
    }

    @Override
    public Iterable<E> findAll() {
        return entities.values();
    }

    @Override
    public E save(E entity) throws ValidatorException {
        if(entity == null) {
            throw new IllegalArgumentException("ENTITY CANNOT BE NULL!");
        }
        validator.validate(entity);
        if(entities.containsKey(entity.getId())) {
            return entity;
        } else {
            entities.put(entity.getId(), entity);
            return null;
        }
    }

    @Override
    public E delete(ID id) {
        if(id == null) {
            throw new IllegalArgumentException("ID CANNOT BE NULL!");
        }
        return entities.remove(id);
    }

    @Override
    public E update(E entity) {
        if(entity == null) {
            throw new IllegalArgumentException("ENTITY CANNOT BE NULL!");
        }
        validator.validate(entity);
        if(entities.containsKey(entity.getId())) {
            entities.put(entity.getId(), entity);
            return null;
        } else {
            return entity;
        }
    }
}
