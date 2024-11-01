package ubb.scs.map.repository.file;

import ubb.scs.map.domain.Utilizator;
import ubb.scs.map.domain.validators.Validator;

import java.io.BufferedWriter;

public class UtilizatorRepository extends AbstractFileRepository<Long, Utilizator>{
    public UtilizatorRepository(Validator<Utilizator> validator, String fileName) {
        super(validator, fileName);
    }

    @Override
    public Utilizator lineToEntity(String line) {
        String[] splited = line.split(";");
        Utilizator u = new Utilizator(splited[1], splited[2]);
        u.setId(Long.parseLong(splited[0]));
        return u;
    }

    @Override
    public String entityToLine(Utilizator entity) {
        String s = entity.getId() + ";" + entity.getFirstName() + ";" + entity.getLastName();
        return s;
    }
}
