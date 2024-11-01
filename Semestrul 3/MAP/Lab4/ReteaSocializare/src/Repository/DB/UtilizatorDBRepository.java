
/**package Repository.DB;

import Domain.Entity;
import Domain.Utilizator;
import Domain.Validators.Validator;
import Repository.Repository;

import java.sql.*;
import java.util.HashSet;
import java.util.Set;

public class UtilizatorDBRepository implements Repository<Long, Utilizator> {
    private String url;
    private String username;
    private String password;
    private Validator<Utilizator> validator;

    public UtilizatorDBRepository(String url, String username, String password, Validator<Utilizator> validator) {
        this.url = url;
        this.username = username;
        this.password = password;
        this.validator = validator;
    }

    @Override
    public Utilizator findOne(Long aLong) {
        return null;
    }

    @Override
    public Iterable<Utilizator> findAll() {
        Set<Utilizator> users = new HashSet<>();
        try (Connection connection = DriverManager.getConnection(url, username, password);
             PreparedStatement statement = connection.prepareStatement("SELECT * from users");
             ResultSet resultSet = statement.executeQuery()) {

            while (resultSet.next()) {
                Long id = resultSet.getLong("id");
                String nume = resultSet.getString("nume");
                String prenume = resultSet.getString("prenume");

                Utilizator utilizator = new Utilizator(nume, prenume);
                utilizator.setId(id);
                users.add(utilizator);
            }
            return users;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public Utilizator save(Utilizator entity) {
        int rez = -1;
        try (Connection connection = DriverManager.getConnection(url, username, password);
             PreparedStatement statement = connection.prepareStatement("INSERT INTO users (nume, prenume) VALUES (?, ?)")) {
            statement.setString(1, entity.getNume());
            statement.setString(2, entity.getPrenume());
            rez = statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if (rez > 0) {
            return null;
        }
        return entity;
    }

    @Override
    public Utilizator delete(Long aLong) {
        return null;
    }

    @Override
    public Utilizator update(Utilizator entity) {
        return null;
    }
}
 **/
