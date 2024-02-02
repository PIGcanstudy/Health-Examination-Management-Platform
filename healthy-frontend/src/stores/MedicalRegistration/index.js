import { defineStore } from 'pinia'
import { ref } from 'vue'
import { queryMedicalPersonName, queryMedicalPersonInfo } from '@/apis/medicalregistration/index.js'
export const useMedicalRegistrationStore = defineStore('MedicalRegistration', () => {
  // 重写方法
  const getMedicalPersonName = async (params) => {
    return await queryMedicalPersonName(params)
  }
  const getMedicalPersonInfo = async (params) => {
    return await queryMedicalPersonInfo(params)
  }
  // 暴露出的数据
  return {
    getMedicalPersonName,
    getMedicalPersonInfo
  }
})
