package Service;

import Domain.Prietenie;
import Domain.Utilizator;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Comunitati {

    Network network;
    HashMap<Long, List<Long>> comunitati;

    public Comunitati(Network network) {
        this.network = network;
    }

    /**
     * Metoda care returneaza numarul de comunitati din retea
     * @return numarul de comunitati din retea
     */
    public int numarComunitati() {
        comunitati = new HashMap<Long, List<Long>>();
        for(Utilizator utilizator: network.getUtilizatori()) {
            List<Long> prieteni = new ArrayList<>();
            for(Prietenie prietenie: network.getPrietenii()) {
                if(prietenie.getIdUtilizator1().equals(utilizator.getId())) {
                    prieteni.add(prietenie.getIdUtilizator2());
                }
                if(prietenie.getIdUtilizator2().equals(utilizator.getId())) {
                    prieteni.add(prietenie.getIdUtilizator1());
                }
            }
            if(!prieteni.isEmpty()) {
                comunitati.put(utilizator.getId(), prieteni);
            }
        }
        List<Long> iduri = new ArrayList<>();
        for (Utilizator utilizator: network.getUtilizatori()) {
            iduri.add(utilizator.getId());
        }

        int numarComunitati = 0;
        HashMap<Long, Boolean> vizitat = new HashMap<Long, Boolean>();
        for(Long i: iduri) {
            if(!vizitat.containsKey(i)) {
                numarComunitati++;
                vizitat.put(i, true);
                dfs(i, vizitat, null);
            }
        }
        return numarComunitati;
    }

    /**
     * Metoda care returneaza cea mai sociabila comunitate
     * @return lista de id-uri a celei mai sociabile comunitati
     */
    public List<Long> ceaMaiSociabila() {
        comunitati = new HashMap<Long, List<Long>>();
        List<Long> maxi = new ArrayList<>();
        for(Utilizator utilizator: network.getUtilizatori()) {
            List<Long> prieteni = new ArrayList<>();
            for(Prietenie prietenie: network.getPrietenii()) {
                if(prietenie.getIdUtilizator1().equals(utilizator.getId())) {
                    prieteni.add(prietenie.getIdUtilizator2());
                }
                if(prietenie.getIdUtilizator2().equals(utilizator.getId())) {
                    prieteni.add(prietenie.getIdUtilizator1());
                }
            }
            if(!prieteni.isEmpty()) {
                comunitati.put(utilizator.getId(), prieteni);
            }
        }
        List<Long> iduri = new ArrayList<>();
        for (Utilizator utilizator: network.getUtilizatori()) {
            iduri.add(utilizator.getId());
        }

        HashMap<Long, Boolean> vizitat = new HashMap<Long, Boolean>();
        for(Long i: iduri) {
            if(!vizitat.containsKey(i)) {
                List<Long> comunitate = new ArrayList<>();
                vizitat.put(i, true);
                dfs(i, vizitat, comunitate);
                if(comunitate.size() > maxi.size()) {
                    maxi = comunitate;
                }
            }
        }
        return maxi;
    }

    /**
     * Metoda care parcuge graful in adancime
     * @param i - nodul de la care incepe parcurgerea
     * @param vizitat - nodurile vizitate
     * @param comunitate - lista de id-uri a comunitatii
     */
    private void dfs(Long i, HashMap<Long, Boolean> vizitat, List<Long> comunitate) {
        if(comunitate != null) {
            comunitate.add(i);
        }
        if(comunitati.containsKey(i)) {
            for(Long j: comunitati.get(i)) {
                if(!vizitat.containsKey(j)) {
                    vizitat.put(j, true);
                    dfs(j, vizitat, comunitate);
                }
            }
        }
    }
}
