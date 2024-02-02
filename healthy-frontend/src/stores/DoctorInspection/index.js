import { defineStore } from 'pinia'
import { queryDangerousInfo, queryAddConclusionList } from '@/apis/doctorinspection/index.js'

export const useDoctorInspectionStore = defineStore('DoctorInspection', () => {
  // 重写方法
  const getDangerousInfo = async (params) => {
    return await queryDangerousInfo(params)
  }
  const getAddConclusionList = async (params) => {
    return await queryAddConclusionList(params)
  }
  // 暴露出数据
  return {
    getDangerousInfo,
    getAddConclusionList
  }
})
